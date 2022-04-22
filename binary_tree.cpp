#include <iostream>
using namespace std;
#include <queue>

class node
{
public:
	int data;
	node *left, *right;
	node(int value)
	{
		data = value;
		left = right = NULL;
	}
};

class BST
{
public:
	node* root;
	BST();
	node* insert_Value(node* r, int value);
	void insert_value(int value);
	void preOrder(node* r);
	void inOrder(node* r);
	void postOrder(node* r);
	void BFT(node* r);
	node* Search(node* r, int key);
	bool Search(int key);
	node* findMin(node* r);
	void findMin();
	node* findMax(node* r);
	void findMax();
	node* Delete(node* r, int key);
};


int main()
{
	// 10	7	2	9	15	13	30
	BST T;
	T.insert_value(10);
	T.insert_value(7);
	T.insert_value(2);
	T.insert_value(9);
	T.insert_value(15);
	T.insert_value(13);
	T.insert_value(30);
	//-------------------------------------------------------------
	cout << "Display the tree content \n";
	cout << "\n--------- PreOrder Traversal ---------\n";
	T.preOrder(T.root);
	cout << "\n------------------\n";
	cout << "\n--------- InOrder Traversal ---------\n";
	T.inOrder(T.root);
	cout << "\n------------------\n";
	cout << "\n--------- PostOrder Traversal ---------\n";
	T.postOrder(T.root);
	cout << "\n------------------\n";
	cout << "\n--------- Breadth First Traversal ---------\n";
	T.BFT(T.root);
	cout << "\n------------------\n";
	//-------------------------------------------------------------
	cout << "\n#Searching...\n";
	int key;
	cout << "Enter item to search for :\n";
	cin >> key;
	(T.Search(key)) ? cout << "item found\n" << endl : cout << "sorry, item not found\n" << endl;
	//-------------------------------------------------------------
	cout << "#Finding the min. and MAX. values in the BST\n";
	T.findMin();
	T.findMax();
	//-------------------------------------------------------------
	cout << "\n\n#Deleting a node in BST\n";
	cout << "Display the tree content before deleting \n";
	T.preOrder(T.root);

	cout << "\n\npreorder after deleting 10\n";
	T.root = T.Delete(T.root, 10);
	T.preOrder(T.root);

	cout << "\n\npreorder after deleting 20\n";
	T.root = T.Delete(T.root, 20);
	T.preOrder(T.root);

	cout << "\n\npreorder after deleting 30\n";
	T.root = T.Delete(T.root, 30);
	T.preOrder(T.root);

	return 0;
}

BST::BST()
{
	root = NULL;
}

node* BST::insert_Value(node* r, int value)
{
	if (r == NULL)
	{
		node* newNode = new node(value);
		r = newNode;
	}
	else if (value < r->data)
		r->left = insert_Value(r->left, value);
	else
		r->right = insert_Value(r->right, value);

	return r;
}

void BST::insert_value(int value)
{
	root = insert_Value(root, value);
}

void BST::preOrder(node* r) //root -> left -> right
{
	if (r != NULL)
	{
		cout << r->data << "\t";
		preOrder(r->left);
		preOrder(r->right);
	}
}

void BST::inOrder(node* r) //left -> root -> right
{
	if (r != NULL)
	{
		inOrder(r->left);
		cout << r->data << "\t";
		inOrder(r->right);
	}
}

void BST::postOrder(node* r) //left -> root -> right
{
	if (r != NULL)
	{
		postOrder(r->left);
		postOrder(r->right);
		cout << r->data << "\t";
	}
}

void BST::BFT(node* r)
{
	if (r == NULL)
		return;
	else
	{
		queue <node*> q;
		
		q.push(r);
		while (!q.empty())
		{
			r = q.front();
			if (r->left != NULL)
				q.push(r->left);

			if (r->right != NULL)
				q.push(r->right);
			cout << r->data << "\t";
			q.pop();
		}
	}
	cout << endl;
}

node* BST::Search(node* r, int key)
{
	if (r == NULL)
		return NULL;
	else if (r->data == key)
		return r;
	else if (key < r->data)
		return Search(r->left, key);
	else
		return Search(r->right, key);
}

bool BST::Search(int key)
{
	//node* result = Search(root, key);
	
	if (Search(root, key) == NULL)
		return false;
	else
		return true;
}

node* BST::findMin(node* r)
{
	if (r == NULL)
		return NULL;
	else if (r->left == NULL) //no elements in the right
		return r; //so the root is the Min
	else
		return findMin(r->left);
}
void BST::findMin()
{
	node* r = findMin(root);
	if (r == NULL)
		cout << "sorry the tree is empty!\n";
	else
		cout << "The min. value is = " << r->data << endl;
}

node* BST::findMax(node* r)
{
	if (r == NULL)
		return NULL;
	else if (r->right == NULL) //no elements in the right
		return r; //so the root is the Max
	else
		return findMax(r->right);
}
void BST::findMax()
{
	node* r = findMax(root);
	if (r == 0) //NULL = 0
		cout << "sorry the tree is empty!\n";
	else
		cout << "The MAX. value is = " << r->data << endl;
}

node* BST::Delete(node* r, int key)
{
	if (Search(key)) {
		if (r == NULL)
			return NULL;  //Empty tree
		else if (key < r->data)  //item exists in left sub tree
			r->left = Delete(r->left, key);
		else if (key > r->data)  //item exists in right sub tree
			r->right = Delete(r->right, key);
		else
		{
			if (r->left == NULL && r->right == NULL) //leaf node
				r = NULL;
			else if (r->left != NULL && r->right == NULL) //one child on the left 
			{
				r->data = r->left->data;
				delete (r->left);
				r->left = NULL;
			}
			else if (r->left == NULL && r->right != NULL)
			{
				r->data = r->right->data;
				delete (r->right);
				r->right = NULL;
			}
			else
			{
				node* MAX = findMax(r->left);
				r->data = MAX->data;
				r->left = Delete(r->left, MAX->data);
			}
		}
		return r; //return r after deleting (new tree)
	}
	else
		cout << "Element Does Not Exist !!\n";
	return r;
}

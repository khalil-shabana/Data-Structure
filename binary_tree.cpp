#include <iostream>
using namespace std;


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
};


int main()
{
	//45 15 79 90 10 55 12 20 50
	BST T;
	T.insert_value(45);
	T.insert_value(15);
	T.insert_value(79);
	T.insert_value(90);
	T.insert_value(10);
	T.insert_value(55);
	T.insert_value(12);
	T.insert_value(20);
	T.insert_value(50);

	cout << "Display the tree content \n";
	T.preOrder(T.root);
	cout << "\n------------------\n";
	T.inOrder(T.root);
	cout << "\n------------------\n";
	T.postOrder(T.root);
	cout << "\n------------------\n";
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
		cout << r->data << " ";
		preOrder(r->left);
		preOrder(r->right);
	}
}

void BST::inOrder(node* r) //left -> root -> right
{
	if (r != NULL)
	{
		inOrder(r->left);
		cout << r->data << " ";
		inOrder(r->right);
	}
}

void BST::postOrder(node* r) //left -> root -> right
{
	if (r != NULL)
	{
		postOrder(r->left);
		postOrder(r->right);
		cout << r->data << " ";
	}
}
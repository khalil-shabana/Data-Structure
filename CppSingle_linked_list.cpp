#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};
class Linked_List {
private :
	node* head;
public:
	Linked_List();
	void show();
	void insert_newnode(int val); //at end
	void insert_firstnode(int val);//at first
	int number_of_elements();
	void insert_atposition(int pos,int val);
	node* search_by_value(int value);
	void delete_first();
	void delete_last();
	void delete_pos(int pos);
	void reverse_list();
	void merge_lists(Linked_List l1, Linked_List l2);
	Linked_List selection_sort(Linked_List l1);
	void Remove_Duplicates(Linked_List l1);
};
//---------------main starts here------------------------------
int main()
{
	Linked_List l1;
	Linked_List l2;
	l1.insert_newnode(1);
	l1.insert_newnode(1);
	l1.insert_newnode(4);
	l1.insert_newnode(5);
	l1.insert_newnode(7);

	l2.insert_firstnode(2);
	l2.insert_firstnode(4);
	l2.insert_firstnode(7);
	l2.insert_firstnode(9);


	//l1.reverse_list();
	cout << " L1 linked list\n";
	l1.show();
	cout << endl;

	cout << " L2 linked list\n";
	l2.show();
	cout << endl;

	cout << "merged list\n";
	l1.merge_lists(l1, l2);
	l1.show();
	cout << endl;

	cout << "------------selection sort--------------\n";
	Linked_List l3; //merged linked list
	l1.selection_sort(l1);
	l1.show();
	cout << endl;

	cout << "-------------Removing Duplicates---------\n";
	l1.Remove_Duplicates(l1);
	l1.show();
	cout << endl;
	return 0;
}
//---------------main ends here------------------------------

Linked_List::Linked_List()
{
	head = NULL;
}

void Linked_List::show()
{
	node* temp = new node;
	temp = head;
	if (head == NULL)
		cout << "Linked List is empty\n";
	while (temp != NULL)
	{
		cout << temp->data << "\t";
		temp = temp->next;
	}
	cout << endl;
}

void Linked_List::insert_newnode(int val)
{
	node* new_node = new node;
	new_node->data = val;
	new_node->next = NULL;

	if (head == NULL)
		head = new_node;
	else
	{
		node* current = new node;
		current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

void Linked_List::insert_firstnode(int val)
{
	node* new_node = new node;
	new_node->data = val;
	if (head == NULL)
	{
		head = new_node;
		head->next = NULL;
	}
	else
	{
		new_node->next = head;
		head = new_node;
	}

}

int Linked_List::number_of_elements()
{
	node* temp = head;
	int counter = 0;
	while (temp != NULL)
	{
		counter++;
		temp = temp->next;
	}
	return counter;
}

void Linked_List::insert_atposition(int pos, int val)
{
	node* new_node = new node;
	new_node->data = val;
	int num = number_of_elements();
	if (pos == 0)
		insert_firstnode(val);
	else if (pos == num)
		insert_newnode(val);
	else if (pos < num)
	{
		node* new_node = new node;
		new_node->data = val;
		node* ptr = head;
		pos--;
		while (pos != 0)
		{
			ptr = ptr->next;
			pos--;
		}
		new_node->next = ptr->next;
		ptr->next = new_node;
	}
	else
		cout << "position is out of the list \n";
}

node* Linked_List::search_by_value(int value)
{
	node* current = head;
	while (current != NULL)
	{
		while (current->data != value)
			current = current->next;
	}
	return current;
}

void Linked_List::delete_first()
{
	if (head == NULL)
		cout<< "list is already empty\n ";
	else
	{
		node* temp = head;
		head = temp->next;
		temp->next = NULL;
		delete temp;
	}
}

void Linked_List::delete_last()
{
	if (head == NULL)
		cout << "List is Empty ! \n";
	else if (head->next == NULL)
		delete head;
	else
	{
		node* prev= head, *curr = head;
		while (curr->next != NULL)
		{
			prev = curr;
			curr = curr->next;
		}
		prev->next = NULL;
		delete curr;
	}
}

void Linked_List::delete_pos(int pos)
{
	int n = number_of_elements();
	if (pos == 0)
		delete_first();
	else if (pos == n-1)
		delete_last();
	else if (pos < n-1)
	{
		node* curr = head;
		node* prev = head;

		while (pos != 0)
		{
			prev = curr;
			curr = curr->next;
			pos--;
		}
		prev->next = curr->next;
		delete curr;
	}
	else
		cout << "position is out of the list \n";
}

void Linked_List::reverse_list()
{
	node* prev = NULL;
	node* next = NULL;
	node* curr = head;

	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

void Linked_List::merge_lists(Linked_List l1, Linked_List l2)
{
	node* temp = l1.head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = l2.head;
}

Linked_List Linked_List::selection_sort(Linked_List l1)
{
	if (l1.head == NULL)
		return l1;
	int temp;
	node* currNode = l1.head;
	node* nextNode = NULL;
	while (currNode != NULL)
	{
		nextNode = currNode->next;
		while (nextNode != NULL)
		{
			if (currNode->data > nextNode->data)
			{
				temp = currNode->data;
				currNode->data = nextNode->data;
				nextNode->data = temp;
			}
			nextNode = nextNode->next;
		}
		currNode = currNode->next;
	}
	return l1;
}

void Linked_List::Remove_Duplicates(Linked_List l1)
{
	node* currentNode = l1.head;
	node* nextNode = NULL;

	while (currentNode->next != NULL)
	{
		if (currentNode->data == currentNode->next->data)
		{
			nextNode = currentNode->next->next;
			delete currentNode->next;
			currentNode->next = nextNode;
		}
		else
		{
			currentNode = currentNode->next;
		}
	}
}


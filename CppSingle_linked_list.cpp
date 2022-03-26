#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

void count_of_nodes(node* head);
void print_data(node* head);
void insert_at_end(node* head, int data);
node* insert_at_beg(node* head, int data);
void add_at_pos(node* head, int data, int pos);
node* del_first(node* head);
void del_last(struct node* head);
void del_pos(node* *head, int position);
node* reverse(node* head);
//---------------main starts here------------------------------
int main()
{
	node* head = new node;
	head->data = 3;
	head->next = NULL;
	
	insert_at_end(head,6);
	count_of_nodes(head);
	print_data(head);
	cout << "\n---------------------\n";
	head=insert_at_beg(head, 9);
	count_of_nodes(head);
	print_data(head);
	cout << "\n---------------------\n";
	add_at_pos(head, 12, 2);
	count_of_nodes(head);
	print_data(head);
	cout << "\n---------------------\n";
	head = del_first(head);
	count_of_nodes(head);
	print_data(head);
	cout << "\n---------------------\n";
	del_last(head);
	count_of_nodes(head);
	print_data(head); //12	3
	cout << "\n---------------------\n";
	insert_at_end(head, 6);
	insert_at_end(head, 9);
	count_of_nodes(head);
	print_data(head); //12 3 6 9 
	cout << "\n---------------------\n";
	del_pos(&head, 3);
	count_of_nodes(head); //3
	print_data(head); //12 3 9
	cout << "\n---------------------\n";
	head = reverse(head);
	print_data(head);
	return 0;
}
//---------------main ends here------------------------------

void count_of_nodes(node* head)
{
	int length=0;
	if (head == NULL)
		cout << "Linked list is Empty ! \n";
	node* ptr = head;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		length ++;
	}
	cout << "the length of linked list = " << length << endl;
}

void print_data(node* head)
{
	if (head == NULL)
		cout << "Linked list is Empty ! \n";

	node* ptr = head;
	while (ptr != NULL)
	{
		cout << ptr->data << "\t";
		ptr = ptr->next;
	}
	cout << endl;
}

void insert_at_end(node* head, int data)
{
	node* temp = new node; //creating a new node
	temp->data = data;
	temp->next = NULL;

	node* ptr = head;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = temp;
}

node* insert_at_beg(node* head, int data)
{
	node* temp = new node;
	temp->data = data;
	temp->next = NULL;
	temp->next = head;
	head = temp;
	return head;
}

void add_at_pos(node* head, int data, int pos)
{
	node* temp = new node;
	node* ptr = head;

	temp->data = data;
	temp->next = NULL;

	pos--;
	if (pos != 1)
	{
		ptr = ptr->next;
		pos--;
	}
	temp->next = ptr->next;
	ptr->next = temp;
}

node* del_first(node* head)
{
	if (head == NULL)
		cout << "list is already empty\n ";
	else
	{
		node* ptr = head;
		head = head->next;
		ptr->next = NULL;
		delete(ptr);
	}
	return head;
}

void del_last(struct node* head)
{
	if (head == NULL)
		cout << "list is already empty\n ";
	else if (head->next == NULL)
		delete(head);
	else
	{
		node* ptr2=head,*ptr1 = head;

		while (ptr1->next != NULL)
		{
			ptr2 = ptr1;
			ptr1 = ptr1->next;
		}
		ptr2->next = NULL;
		delete(ptr1);
	}
}

void del_pos(node* *head, int position)
{
	node* current = *head;
	node* previous = *head;

	if (*head==NULL)
		cout << "list is already empty\n ";
	else if (position == 1)
	{
		*head = current->next;
		current->next = NULL;
		delete(current);
	}
	else
	{
		while (position != 1)
		{
			previous = current;
			current = current->next;
			position--;
		}
		previous->next = current->next;
		current->next = NULL;
		delete(current);
	}
}

node* reverse(node* head)
{
	struct node* prev = NULL;
	struct node* next = NULL;
	while (head != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	head = prev;
	return head;
}
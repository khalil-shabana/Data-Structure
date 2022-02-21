#include <stdio.h>
#include <stdlib.h>

struct node		
{
	int data;
	struct node* link;	//self referential structure
};
int count;
void count_of_nodes(struct node* head)
{
	if (head == NULL)
		printf("linked list is empty!\n");

	struct node* ptr = NULL;
	ptr = head;

	while (ptr != NULL)
	{
		ptr = ptr->link;
		count++;
	}
	printf("%d \n", count);
}
void print_data(struct node* head)
{
	if (head == NULL)
		printf("linked List is empty!\n");
	struct node* ptr = NULL;
	ptr = head;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
}
struct node* add_at_end(struct node* ptr, int data)
{
	struct node* temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	
	ptr->link = temp;
	return temp;
}
struct node* add_at_beg(struct node* head, int data)
{
	struct node* ptr = malloc(sizeof(struct node));
	ptr->data = data;
	ptr->link = NULL;

	ptr->link = head;
	head = ptr;
	return head;
}
void add_at_pos(struct node* head,int data, int pos)
{
	struct node* ptr = head;
	struct node* ptr2 = malloc(sizeof (struct node)); //new node
	ptr2->data = data;
	ptr2->link = NULL;

	pos--; //NOTE : we need to stand at (pos-1)

	while (pos != 1)
	{
		ptr = ptr->link; //updating
		pos--;
	}
	ptr2->link = ptr->link;
	ptr->link = ptr2;

}
struct node* del_first(struct node* head)
{
	if (head == NULL)
	{
		printf("list is already empty!");
	}
	else
	{
		struct node* temp = head;
		head = head->link;
		free(temp);
		temp = NULL;
	}
	return head;
}
int main()
{
	struct node* head =(struct node*) malloc(sizeof (struct node)); //creating 1-st node
	//type casting is not necessary but it's a good practice.
	head->data = 45;
	head->link = NULL;
	
	head= add_at_beg(head, 214);
	head= add_at_beg(head, 102);
	head= add_at_beg(head, 98);
	
	add_at_pos(head, 14, 4);

	print_data(head);

	head = del_first(head);

	printf("\n\nAfter deleting the first node\n\n");
	
	print_data(head);
	
	return 0;
}
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
int main()
{
	struct node* head =(struct node*) malloc(sizeof (struct node)); //creating 1-st node
	//type casting is not necessary but it's a good practice.
	head->data = 45;
	head->link = NULL;
	
	struct node *ptr = head;
	ptr = add_at_end(ptr, 98);
	ptr = add_at_end(ptr, 102);
	ptr = add_at_end(ptr, 214);
	
	count_of_nodes(head);
	print_data(head);
	return 0;
}
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
int main()
{
	struct node* head =(struct node*) malloc(sizeof (struct node)); //creating a new node
	//type casting is not necessary but it's a good practice.
	head->data = 45;
	head->link = NULL;

	struct node* current = malloc(sizeof(struct node));	
	current->data = 98;
	current->link = NULL;
	head->link = current; //the first node is connected to the second node now
	
	current = malloc(sizeof(struct node)); //third-node
	current->data = 102;
	current->link = NULL;
	head->link->link = current;
	//head->link means accessing first node
	//head->link->link ==>> 1st_node->link means accessing the second node
	//head->link->link = current means 2nd_node points to the 3rd_node
	
	count_of_nodes(head);
	print_data(head);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node		
{
	int data;
	struct node* link;	//self referential structure
};

int main()
{
	struct node* head =(struct node*) malloc(sizeof (struct node)); //creating a new node
	//type casting is not necessary but it's a good practice.
	head->data = 45;
	head->link = NULL;

	printf("%d ", head->data);

	return 0;
}
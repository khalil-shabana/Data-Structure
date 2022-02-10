#include<stdio.h>
#define MAX_SIZE 4


int stack_arr[MAX_SIZE];
int top = -1; //the stack is empty


int isFULL()
{
	if (top == MAX_SIZE - 1)
		return 1;
	else
		return 0;
}
int isEmpty()
{
	if (top == -1)
		return 1;
	else
		return 0;	
}
void push(int data)
{
	if (isFULL())
	{
		printf("\nStack overflow\n\n");
		return;
	}
		top++;
		stack_arr[top] = data;
}
int pop()
{
	int value;
	if (isEmpty())
	{
		printf("Stack underflow -> ");
		printf("no elements in the stack\n");
		exit(1);	//abnormal termination of the program
	}
	value = stack_arr[top];
	top--;
	return value;
}
int peek()
{
	if (isEmpty())
	{
		printf("Stack underflow -> ");
		printf("no elements in the stack\n");
		exit(1);
	}
	return stack_arr[top];
}
void print()
{
	int i;
	if (isEmpty())
	{
		printf("Stack underflow -> ");
		printf("no elements in the stack\n");
		return;
	}
	for (i = top; i >= 0; i--)
	{
		printf("%d \n", stack_arr[i]);
	}
}


int main() {
	int choice, data;
	while (1)
	{
		printf("-------------------------------------------\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Print the top element\n");
		printf("4. Print all the elements of the stack\n");
		printf("5. Quit\n");
		printf("Please enter your choice: ");
		scanf_s("%d", &choice);
		printf("-------------------------------------------\n");

		switch (choice)
		{
		case 1:
			printf("\nEnter the element to be pushed: ");
			scanf_s("%d", &data);
			push(data);
			break;

		case 2:
			data = pop();
			printf("\nDeleted element is %d\n", data);
			break;

		case 3:
			data = peek();
			printf("\nThe topmost element of the stack is %d ",data);
			printf("\n");
			break;

		case 4:
			print();
			break;

		case 5:
			exit(1);

		default :
			printf("Wrong choice\n");
		}
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

int add_at_end(int a[], int freePos, int data)
{
	a[freePos] = data;
	freePos++;
	return freePos;
}

int main()
{
	int a[10];
	int i, n, freePos;
	printf("Enter the number of elements : ");
	scanf_s("%d", &n);

	for (i = 0;i < n;i++)
	{
		printf("Enter element number %d : ",i+1);
		scanf_s("%d", &a[i]);
	}
	freePos = n;
	freePos = add_at_end(a, freePos, 65);

	for (i = 0; i < freePos;i++) {
		printf("\n%d\n", a[i]);
	}
	return 0;
}
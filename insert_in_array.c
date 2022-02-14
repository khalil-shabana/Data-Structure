#include <stdio.h>
#include <stdlib.h>

void add_at_pos(int arr[], int arr2[], int n, int data, int pos)
{
	int i;
	int index = pos - 1;
	for (i = 0;i < index;i++)
	{
		arr2[i] = arr[i];
	}
	arr2[index] = data;
	int j;
	for (i = index + 1, j = index;i < n + 1, j < n;i++, j++)
	{
		arr2[i] = arr[j];
	}
}
void printing(int arr[], int n)
{
	int i;
	for (i = 0;i < n;i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[] = { 2,34,21,6,7,8,90,67,23,39 };
	int pos = 5, data = 78, i;
	int size = sizeof(arr) / sizeof(arr[0]);
	int arr2[size + 1];
	add_at_pos(arr, arr2, size, data, pos);

	printf("Array before insertion :\n");
	printing(arr, size);
	printf("\n----------------------------\n");
	printf("Array after insertion :\n");
	printing(arr2, size + 1);

	return 0;
}
#include <iostream>

using namespace std;

void insertion_sort(int arr[], int n);
void display(int arr[],int n);
int main()
{
    int arr[]={80,60,40,50,30,10,50,75,100,20};
    int length=sizeof(arr)/sizeof(arr[0]);
    //display before sorting
    cout<<"---------- before sorting ----------\n";
    display(arr,length);
    insertion_sort(arr,length);
        //display after sorting
    cout<<"---------- after sorting ----------\n";
    display(arr,length);
    return 0;
}

void insertion_sort(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        int value=arr[i];
        int hole=i;
        while (hole >0 && arr[hole-1]>value)
        {
            arr[hole]=arr[hole-1];
        hole--;
        }
        arr[hole]=value;
    }
}

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

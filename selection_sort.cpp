#include <iostream>

using namespace std;

void selection_sort(int arr[], int n);
void display(int arr[],int n);
int main()
{
    int arr[]={80,60,40,50,30,10,50,75,100,20};
    int length=sizeof(arr)/sizeof(arr[0]);
    //display before sorting
    cout<<"---------- before sorting ----------\n";
    display(arr,length);
    selection_sort(arr,length);
        //display after sorting
    cout<<"---------- after sorting ----------\n";
    display(arr,length);
    return 0;
}

void selection_sort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_Indix=i;
        for(int j=i+1;j<=n-1;j++)
        {
            if(arr[j]<arr[min_Indix])
                min_Indix=j;
        }
        swap(arr[i],arr[min_Indix]);
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

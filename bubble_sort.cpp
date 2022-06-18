#include <iostream>

using namespace std;

void bubble_sort(int arr[], int n);
void display(int arr[],int n);
int main()
{
    int arr[]={80,60,40,50,30,10,50,75,100,20};
    int length=sizeof(arr)/sizeof(arr[0]);
    //display before sorting
    cout<<"---------- before sorting ----------\n";
    display(arr,length);
    bubble_sort(arr,length);
        //display after sorting
    cout<<"---------- after sorting ----------\n";
    display(arr,length);
    return 0;
}

void bubble_sort(int arr[], int n)
{
    bool flag=true;
    //if there is no any swap in first iteration -> flag remains = true -> and it means that array is already sorted
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=n-2;j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
                flag=false;
        }
        if(flag==true) break;
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

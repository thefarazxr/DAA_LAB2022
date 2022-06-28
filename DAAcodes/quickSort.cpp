#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void swap(int &x,int&y)
{
    int temp=x;
    x=y;
    y=temp;
}

int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    
    for(int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quickSort(int arr[], int low,int high)
{
    if(low<high)
    {
        int pivot=partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}

int main()
{
    // int arr[] = new int[10000];
    int arr[10000];
    int n = 0;
    
    // clock_t start,end;
    
    
    cout << "Enter size";
    cin >> n;
    cout << "\n The random numbers are:" << endl;
    for (int k = 0; k < n; k++)
    {
        arr[k] = rand() % 100 + 1; // random number form 1 to 100
        cout << arr[k] << " ";
    }
    // start=clock();
    
    quickSort(arr,0,n-1);
    
    // end=clock();
    // double cpu_time_used=((double)end-start)/CLOCKS_PER_SEC;
    cout<<"\nAfter:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    // cout<<"\n CPU time useage=>  "<<cpu_time_used;
    return 0;
}

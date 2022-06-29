#include<iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high){     //comparing and merging
   int temp[high];
     
     int i=low;   //traverses a[] array
     int j=mid+1;    //traverses b[] array
     int k=low;     //traverse in main array
     
     while(i<=mid&& j<=high)
     {
         if(arr[i]<arr[j])
         {
             temp[k]=arr[i];
             i++;k++;
         }
         else
         {
             temp[k]=arr[j];
             j++;k++;
         }
     }
     
     while(i<=mid)
     {
         temp[k]=arr[i];
             i++;k++; 
     }
     
      while(j<=high)
     {
         temp[k]=arr[j];
             j++;k++; 
     }
     
     
     for(int i=low;i<=high;i++)
     {
         arr[i]=temp[i];
     }
}


void merge_sort(int arr[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        
        merge(arr,low,mid,high);
    }
}

int main()
{
    int arr[ ]= {6,23,5,78,392,102,64};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout<<"BEFORE SORTING ";
    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";  
    }

    cout<<"\nAFTER SORTING ";
    merge_sort(arr,0,n-1);
     
     for(int i=0;i<n;i++)
     {
    cout<<arr[i]<<" ";  
    }
    return 0;
}


//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low<high)
        {
            int loc=partition(arr,low,high);
            quickSort(arr,low,loc-1);
            quickSort(arr,loc+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
         int start = low;
         int end= high;
         
         int pivot = arr[low];
         
         while(start<end)
         {
         
         while(arr[start]<=pivot)
         {
             start++;
         }
         
         while(arr[end]>pivot)
         {
             end--;
         }
         
         if(start<end)
         {
            //  int temp=arr[start];
            //  arr[start]=arr[end];
            //  arr[end]=temp;
             swap(arr[start],arr[end]);
         }
         }
        //  int temp=arr[end];
        //      arr[end]=arr[high];
        //      arr[high]=temp;
         swap(arr[end],arr[low]);
         return end;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends
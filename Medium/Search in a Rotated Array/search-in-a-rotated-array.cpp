//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    int pivotEle(int arr[], int l, int h) {
        int start = l;
        int end = h;
        int mid = start + (end - start) / 2;
        while (start < end) {
            if (arr[mid] >= arr[l]) { 
                start = mid + 1;
            } else {
                end = mid;
            }
            mid = start + (end - start) / 2;
        }
        return start;
    }
     int minindex(int a[],int n){
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int pre=(mid+n-1)%n;
            int next=(mid+1)%n;
            if(a[mid]<a[pre] && a[mid]<a[next]){
                return mid;
            }
            else if(a[mid]<a[h]){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
    }
public:
    int search(int arr[], int l, int h, int key) {
        int pivot = pivotEle(arr, l, h);
        int start, end;
        if (key >= arr[pivot] && key <= arr[h]) {
            start = pivot;
            end = h ;
        } else {
            start = l;
            end = pivot - 1;
        }
        int mid = start + (end - start) / 2;
        while (start <= end) {
            if (arr[mid] == key) {
                return mid;
            } else if (arr[mid] < key) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }
        return -1;
    }

};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends
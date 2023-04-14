//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    vector<long long> nextSmallerElement(long long arr[] , int n){
        vector<long long>next(n);
        stack<int>st;
        st.push(-1);
        for(int i = n-1; i>=0; i--){
            int curr = arr[i];
            while(st.top() != -1 and arr[st.top()] >= curr){
                st.pop();
            }
            next[i] = st.top();
            st.push(i);
        }
        return next;
    }
    vector<long long> prevSmallerElement(long long arr[] , int n){
        vector<long long>next(n);
        stack<int>st;
        st.push(-1);
        for(int i = 0; i<n; i++){
            int curr = arr[i];
            while(st.top() != -1 and arr[st.top()] >= curr){
                st.pop();
            }
            next[i] = st.top();
            st.push(i);
        }
        return next;
    }
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long>next(n);
        next = nextSmallerElement(arr , n);
        vector<long long>prev(n);
        prev = prevSmallerElement(arr ,n);
        long long maxArea = 0;
        for(int i = 0; i<n; i++){
            if(next[i] == -1)
                next[i] = n;
            long long length = arr[i];
            long long breadth = next[i] - prev[i] - 1;
            long long newArea = length * breadth;
            maxArea = max(maxArea , newArea);
        }
        return maxArea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends
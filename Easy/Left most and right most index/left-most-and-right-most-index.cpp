//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    int leftOcc(vector<long long>& arr , int key){
        int start = 0;
        int end = arr.size() - 1;
        int mid = start + (end - start)/2;
        int ans = -1;
        while(start <= end){
            
            if(arr[mid] == key){
                ans = mid;
                end = mid - 1;
            }else if(key > arr[mid]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }
    int rightOcc(vector<long long>& arr , int key){
        int start = 0;
        int end = arr.size() - 1;
        int mid = start + (end - start)/2;
        int ans = -1;
        while(start <= end){
            
            if(arr[mid] == key){
                ans = mid;
                start = mid + 1;
            }else if(key > arr[mid]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        pair<long, long>p;
        p.first = leftOcc(v,x);
        p.second = rightOcc(v,x);
        return p;
        
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends
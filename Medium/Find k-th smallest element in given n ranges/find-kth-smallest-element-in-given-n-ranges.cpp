//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    vector<vector<int>> mergeIntervals(vector<vector<int>> &range){
        int n=range.size();
        vector<vector<int>> v;
        int i=0;
        while(i<n){
            int start=range[i][0];
            int en=range[i][1];
            while((i+1<n)&&range[i+1][0]<=range[i][1]){
                en=max(en,range[i+1][1]);
                i++;
            }
            v.push_back({start,en});
            i++;
        }
        return v;
    }
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
        vector<int> res;
        sort(range.begin(),range.end(),cmp);
        range=mergeIntervals(range);
        n=range.size();
        for(int i=0;i<q;i++){
            int x=queries[i];
            int count=0;
            int j=0;
            for(j=0;j<n;j++){
                vector<int> v=range[j];
                int cur_count=v[1]-v[0]+1;
                if(cur_count>=x){
                    res.push_back(v[0]+x-1);
                    break;
                }
                count+=cur_count;
                x-=cur_count;
            }
            if(j==n)
            res.push_back(-1);
        }
        return res;
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends
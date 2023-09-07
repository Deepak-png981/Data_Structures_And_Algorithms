//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end)
    {
        queue<int>q;
        q.push(start);
        vector<bool>visited(1e5,false);
        visited[start]=true;
        int step=0;
        int m=1e5;
       
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int x=q.front();
                q.pop();
                if(x==end)return step;
                for(int i=0;i<arr.size();i++)
                {
                    int y=(x*arr[i])%m;
                    if(visited[y]==false)
                    {
                       visited[y]=true;
                        q.push(y);
                    }
                }
            }
            step++ ;
        }
        
        return -1 ;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
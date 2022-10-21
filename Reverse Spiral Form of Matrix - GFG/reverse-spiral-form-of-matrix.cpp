//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        vector<int>ans;
        if(R == 0)  return ans;
        vector<vector<bool>>vis(R , vector<bool>(C ,false));
        int deltaRow[] = {0 , 1 , 0 , -1};
        int deltaCol[] = {1 ,  0 , -1 ,  0};
        int x = 0 , y  = 0  , di = 0;
        for(int i = 0; i<R*C; i++){
            ans.push_back(a[x][y]);
            vis[x][y] = true;
            int newX = x + deltaRow[di];
            int newY = y + deltaCol[di];
            if(newX >= 0 and newX < R and newY >= 0 and newY < C and 
                !vis[newX][newY]){
                    x = newX;
                    y = newY;
                }
            else{
                di = (di + 1 )%4;
                x = x + deltaRow[di];
                y = y + deltaCol[di];
            }
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
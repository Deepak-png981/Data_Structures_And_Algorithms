//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		   vector<int> freq(26,0);
    queue<char> que;
    string ans;
    
    for (int i = 0; i < A.size(); i++)
    {
        freq[A[i] - 'a']++;
        
        if (freq[A[i] - 'a'] <= 1)
          que.push(A[i]);
          
        int flag = 0;
        
        while (!que.empty())
        {
            char x = que.front();
            if (freq[x-'a'] == 1)
            {
                ans += x;
                flag = 1;
                break;
            }
            else
                que.pop();
        }
        
        if (que.empty() and flag == 0)
            ans += '#';
    }
    return ans;
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{  
private:
    long long resolve(string &S , string check , int amount){
        long long i = 0 , ans = 0;
        for(int j = 0; j<S.size(); j++){
            S[i++] = S[j];
            if(i >= 2 and S[i-2] == check[0] and S[i-1] == check[1]){
                i -= 2;
                ans += amount;
            }
        }
        S.resize(i);
        return ans;
    }
public:
    long long solve(int X,int Y,string S){
      string a = "pr" , b = "rp";
      if(X < Y){
          swap(X , Y);
          swap(a , b);
      }
      return resolve(S , a ,X) + resolve(S , b , Y);
    }
};
//pr ->X = 5
//rp >Y = 4
//   S = "abppprrr"
//   S = "abpprr"   5
//   S = "abpr"     5
//   s =  "ab"      5
// total = 15 


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends
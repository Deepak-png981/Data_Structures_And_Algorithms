//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int nums[], int n)
    {
       
        if(n == 0)  return 0;
        sort(nums , nums + n);
        int count = 0 , longest = 1 , lastsq = INT_MIN;
        for(int i = 0; i<n; i++){
            if(nums[i] == lastsq + 1){
                count++;
                lastsq++;
            }else if(nums[i] != lastsq){
                count = 1;
                lastsq = nums[i];
            }
            longest = max(longest , count);
                
        }
        return longest;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends
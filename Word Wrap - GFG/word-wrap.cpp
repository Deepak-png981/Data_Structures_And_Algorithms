//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
     int solve(int index,vector<int>&nums,int k,vector<int>&dp){
        //k is the max size f words in each line


        if(index>=nums.size()-1)return 0;    //if it is the last word
        if(dp[index]!=-1)return dp[index];
        
        int val=0;
        int mini=1e9;
        
        for(int i=index;i<nums.size();i++){
            
            val=val+nums[i];         //size of words 
            int gap=i-index;           //it is gap between words
            if(val+gap<=k && i<nums.size()-1){         //we can still insert more words
                
                int cost=pow(k-(val+gap),2)+solve(i+1,nums,k,dp);
                mini=min(mini,cost);
            }
            
            else if(val+gap<=k && i==nums.size()-1){    //this is for the last word being inserted
                return dp[index]=0;      //index se laekar i tak sare words are in this row along with last word
                //hense its cost is zero
            }
        }
            
                return dp[index]=mini;
            
          
        
        
    }
    
    
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
       int n=nums.size();
       vector<int>dp(n,-1);
       return solve(0,nums,k,dp);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends
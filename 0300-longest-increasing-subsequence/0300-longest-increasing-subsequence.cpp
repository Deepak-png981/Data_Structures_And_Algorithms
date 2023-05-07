class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

    //  N is the size of the nums
     int N=nums.size();
     //  we will take the dp og size of N
     int dp[N];
    //  we will take our ans 1 at first if no Increasing Subsequence is found 
     int ans =1;
   //  we triverse from end(N-1) to 0
     for(int i=N-1;i>=0;i--){

         int maxx =0;
   // for last element Longest Increasing Subsequence will be 1 (base condition)
          if(i==N-1){
              dp[i]=1;
              ans= max(ans,dp[i]);
              continue;
           }
  // if any element is grater than current then Longest Increasing Subsequence will be 1 + (Longest Increasing Subsequence )of that element
       for(int j=i+1;j<N;j++){  

         if(nums[i]<nums[j]){ 
           //  to find the max of last dp elements
             maxx= max(maxx,dp[j]);
           }
       }
        dp[i]= 1+maxx;
        ans= max(ans,dp[i]);
     }

    return ans;
    }
        
};
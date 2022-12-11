class Solution {
public:
    vector<vector<int>> ans;
    //  void f(vector<int> nums,int i,int n)
    // {
    //     if(i==n)
    //     {
    //         ans.push_back(nums);
    //         return ;
    //     }
    //     for(int j=i;j<=n;j++)
    //     {
    //         if(j!=i && nums[i]==nums[j]) continue;
    //         swap(nums[i],nums[j]);
    //         f(nums,i+1,n);
    //     }
    // }
    void f(vector<int>nums , int i , int n){
        if(i == n)
        {
            ans.emplace_back(nums);
            return;
        }
        for(int j = i; j <= n; j++){
            if( j != i and nums[i] == nums[j])
                continue;
            swap(nums[i] , nums[j]);
            f(nums , i+1 , n);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        f(nums , 0 , nums.size() - 1);
        return ans;
    }
};
class Solution
{
    private:
       	//pick and not pick approach
        void helper(int index, vector<int> &arr, int target, vector<vector< int >> &ans, vector< int > &ds)
        {
            if (index == arr.size())
            {
                if (target == 0)
                {
                    ans.push_back(ds);
                }
                return;
            }
           	//picking up the element
            if (arr[index] <= target)
            {
                ds.push_back(arr[index]);
                helper(index, arr, target - arr[index], ans, ds);
                ds.pop_back();
            }
            helper(index + 1, arr, target, ans, ds);
        }
    public:
        vector<vector < int>> combinationSum(vector<int> &candidates, int target)
        {
            vector<vector < int>> ans;
            vector<int> ds;
            helper(0, candidates, target, ans, ds);
            return ans;
        }
};
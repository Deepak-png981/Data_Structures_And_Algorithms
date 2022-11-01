class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int diff = INT_MAX , ans = 0;
        for(int i = 0; i<n; i++){//fixing the first element
            int first = nums[i];
            int left = i+1 , right = n-1;
            while(left < right){ 
             //<= isliye nhi kiya kyuki ush point per dono same element ko hi point ker rhe honge or triple sum mein do same index ke element nhi le sakte hai mere bhai
                if( first + nums[left] + nums[right] == target)
                    return target;
                else if(abs( (first + nums[left] + nums[right]) - target ) < diff){
                    diff = abs( (first + nums[left] + nums[right]) - target );
                    ans = first + nums[left] + nums[right];
                }
                if( (first + nums[left] + nums[right]) > target)
                    right--;
                else
                    left++;
            }
        }
        return ans;
}
};
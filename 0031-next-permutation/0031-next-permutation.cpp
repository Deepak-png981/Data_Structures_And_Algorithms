class Solution {
public:
    void nextPermutation(vector<int>& nums) {
//    Using inbuilt function
        // int n = nums.size();
        // next_permutation(nums.begin() , nums.end());
        
//         using logic
        int n = nums.size();
        int idx = -1;
        //traversing from the back of the array
        for(int i = n-1; i>0; i--){
        //comparing .. finding out the index for which the next element is smaller than the current element
            if(nums[i] > nums[i-1]){
                idx = i; //idx mein i store ker liye
                break;
            }
        }
        //decreasnig hoga to wo handle kiya hai yaha
        if(idx == -1){
            reverse(nums.begin() , nums.end());
        }
        else{
        int prev = idx;
            for(int i = idx+1; i<n; i++){
                if(nums[idx-1] < nums[i] and nums[i] <= nums[prev])
                    prev = i;
            }
            swap(nums[idx-1] , nums[prev]);
            reverse(nums.begin() + idx , nums.end());
        }
        return;
    }
};
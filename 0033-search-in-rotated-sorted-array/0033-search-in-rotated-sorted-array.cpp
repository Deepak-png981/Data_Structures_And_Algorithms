class Solution {
private:
    int getPiovt(vector<int>nums){
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + ( e - s )/2;
        while(s < e){
            if(nums[mid] >= nums[0]){
                s = mid + 1;
            }
            else
                e = mid;
            mid = s + ( e - s )/2;
        }
        return s;
    }
    int binarySearch(vector<int>nums , int s , int e , int key){
        int mid = s + (e - s)/2;
        while(s <= e){
            if(nums[mid] == key )
                return mid;
            else if(nums[mid] < key){
                s = mid + 1;
            }else
                e = mid - 1;
            mid = s + (e - s)/2;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int pivot = getPiovt(nums);
        int n = nums.size() - 1;
        if(nums[pivot] <= target and target <= nums[n])
            return binarySearch(nums , pivot , n  , target);
        else
        return binarySearch(nums , 0 , pivot-1 , target);
    }
};
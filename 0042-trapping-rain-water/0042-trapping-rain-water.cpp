class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int maxleft = 0 , maxright = 0;
        int left = 0 , right = n-1;
        int ans = 0;
        while(left <= right){
            if(arr[left] <= arr[right]){
                if(arr[left] >= maxleft)
                    maxleft = arr[left];
                else
                    ans += maxleft - arr[left];
                left++;
            }else{
                if(arr[right] >= maxright){
                    maxright = arr[right];
                }else{
                    ans += maxright - arr[right];
                }
                right--;
            }
        }
        return ans;
    }
};
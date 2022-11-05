class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0 , right = n - 1;
        int area = INT_MIN;
        for(int i = 0; i< n ; i++){
            area = max( area , min( height[left] , height[right] )  * ( right - left ) );
            ( height[right] > height[left] ) ? left++ : right--;
        }
        return area;
    }
};
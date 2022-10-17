class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0 , right = n-1 , area = 0; 
        for(int i = 0; i<n; i++){
            area = max ( area , min ( height[left] , height[right] ) * ( right - left ) );
            (height[left] > height[right]) ? right-- : left++;
        }
        return area;
    }
};
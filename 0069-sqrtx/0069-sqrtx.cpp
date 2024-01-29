class Solution {
private: 
    int binarySearch(int n){
        int start = 1;
        int end = n;
        long long int mid = start + (end - start)/2;
        long long int ans = 0;
        while(start <= end){
            long long int square = mid * mid;
            if(square == n){
                return mid;
            }else if(square < n){
                ans = mid;
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
        
    }
public:
    int mySqrt(int x) {
        return binarySearch(x);   
    }
};
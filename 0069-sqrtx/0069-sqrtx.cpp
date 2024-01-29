class Solution {
private:
    long long int binarySearch(int x){
        int s = 0;
        int e = x;
        long long int mid = s + ( e - s )/2;
        long long int ans = -1;
        while(s <= e ){
            long long int sqrt = mid * mid;
            if(sqrt == x)
                return mid;
            if( sqrt < x ){
                ans = mid;
                s = mid + 1;
            }else{
                e = mid - 1;
            }
            mid = s + ( e - s )/2;
        }
        return ans;
    }
public:
    int mySqrt(int x) {
        return binarySearch(x);
    }
};
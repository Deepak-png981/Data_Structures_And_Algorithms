class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        if(n < 0){
            nn = -nn;
        }
        double ans = 1.0;
        while(nn){
            if(nn % 2){ //odd
                ans = ans * x;
                nn = nn-1;
            }else{ //even
                x = x * x;
                nn = nn/2;
            }
        }
        return n < 0 ? (double)1.0/ans : ans;
    }
};
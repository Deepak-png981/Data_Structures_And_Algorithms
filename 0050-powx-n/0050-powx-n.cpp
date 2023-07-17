class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        if(nn < 0){
            nn = -1 * nn;
        }
        double ans = 1.0;
        while(nn){
            if(nn % 2 == 1){
                nn--;
                ans = ans*x;
            }else{
                x = x*x;
                nn = nn/2;
            }
        }
        if(n < 0)
            return (double)(1.0)/(double)ans;
        else
            return ans;
    }
};
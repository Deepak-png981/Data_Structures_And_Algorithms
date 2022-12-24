class Solution {
public:
    int numTilings(int n) {
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        if(n == 3)
            return 5;
        int mod = 1000000007;
        long a = 1 , b = 2 , c = 5 , res = 0;
        while(n--){
            if(n < 3){
                break;
            }
            res = (a + 2*c)%mod;
            a = b;
            b = c;
            c = res;
            
        }
        return res;
    }
};
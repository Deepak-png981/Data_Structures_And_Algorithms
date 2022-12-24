class Solution {
// https://leetcode.com/problems/domino-and-tromino-tiling/discuss/2944400/C%2B%2B-Simple-idea-and-code-(0ms-runtime).-Explain-by-image-and-comment.
public:
    int numTilings(int n) {
         int mod = 1000000007;
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        if(n == 3)
            return 5;
        long a = 1 , b = 2 , c = 5, res  = 0;
        //logic is An = An-3 + An-1 * 2
        while(n--){
            if(n < 3)
                break;
            res = (2*c + a)%mod;
            a = b;
            b = c;
            c = res;
        }
        return res;
    }
};
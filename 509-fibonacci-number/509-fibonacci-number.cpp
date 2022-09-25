class Solution {
public:
    int fib(int n) {
        // int first = 0 , second = 1 , fib;
        // for(int i = 1; i<n; i++){
        //     fib = first + second;
        //     first = second;
        //     second = fib;
        // }
        // return fib;
        
//         using two variables only
        int a = 0 , b = 1;
        if(n == 0)
            return 0;
        for(int i = 1; i<n; i++){
            b += a;
            a = b - a;
        }
        return b;
    }
};
class Solution {
public:
    int fib(int n) {
        int first = 0 , second = 1 , fib;
        for(int i = 0; i<n-1; i++){
            fib = first + second;
            first = second;
            second = fib;
        }
        return fib;
    }
};
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long start=1, end=n, mid;
        while( start<=end){
            
            mid= (start+end)/2;

            if( guess((int)mid)==0) return (int)mid;
            else if( guess((int)mid)==1) start=mid+1;
            else end=mid-1; 
        }

        return -1;
    }
};
class Solution {
public:
    int minFlipsMonoIncr(string s) {
       int counter = 0 , flips = 0;
        for(auto ch : s){
            if(ch == '1')
                counter++;
            else
                flips++;
            flips = min(flips , counter);
        }
        return flips;
    }
};
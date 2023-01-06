class Solution {
public:
    int maxIceCream(vector<int>& vec, int coins) {
        sort(vec.begin(), vec.end());
        
        int count = 0;
        
        for(auto it : vec){
            if(coins - it < 0)
                return count;
            else{
                coins -= it;
                count++;
            }
        }
        return count;
    }
};
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
    // [91,54,63,99,24,45,78]
    // [35,32,45,98,6,1,25]
    // 17
        for(int i = 0; i<n; i++){
            rocks[i] = capacity[i] - rocks[i];
        }
        int sum = 0 , cnt = 0;
        sort(rocks.begin() , rocks.end());
        for(int i = 0; i<n; i++){
            sum += rocks[i];
            if(sum > additionalRocks){
                break;
            }
            else
                cnt++;
        }
        return cnt;
    }
};
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        int cnt =0;        
        int sum = 0;
        for(int i = 0; i<n; i++){
            rocks[i] = capacity[i] - rocks[i];
        }
        sort(rocks.begin() , rocks.end());
        for(int i = 0; i<n; i++){
            sum += rocks[i];
            if(sum > additionalRocks)
                break;
            else
                cnt++;
        }
        return cnt;
    }
};
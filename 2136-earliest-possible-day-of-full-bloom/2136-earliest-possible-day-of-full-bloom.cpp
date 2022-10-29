class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>> pr;
        int n = plantTime.size();
        for(int i = 0; i< n ; i++)
            pr.emplace_back(growTime[i] , plantTime[i]);
        sort(pr.rbegin() , pr.rend());
        int count = 0 , time = 0;
        for(auto[g , p] : pr){
            count += p;
            time = max(time , count + g);
        }
        return time;
    }
};
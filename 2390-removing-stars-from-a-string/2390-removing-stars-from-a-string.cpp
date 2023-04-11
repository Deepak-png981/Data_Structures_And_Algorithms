class Solution {
public:
    string removeStars(string s) {
        vector<int>res;
        for(auto it : s){
            if(it != '*')
                res.push_back(it);
            else
                res.pop_back();
        }
        string result(res.begin() , res.end());
        return result;
    }
};
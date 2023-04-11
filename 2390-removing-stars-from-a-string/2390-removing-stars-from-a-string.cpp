class Solution {
public:
    string removeStars(string s) {
        vector<int>ans;
        for(char it : s){
            if(it != '*'){
                ans.push_back(it);
            }
            else{
                ans.pop_back();
            }
        }
        string result(ans.begin() , ans.end());
        return result;
    }
};

//leet**cod*e
//lecoe




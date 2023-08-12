class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>v;
        int fact = 1;
        for(int i = 1; i<n; i++){
            v.push_back(i);
            fact = fact*i;
        }
        v.push_back(n);
        k--; //for zero base indexing
        string ans = "";
        while(true){
            ans = ans + to_string( v[k/fact] );
            v.erase(v.begin() + k/fact);
            if(v.size() == 0)
                break;
            k = k%fact;
            fact = fact/v.size(); 
        }
        return ans;
    }
};
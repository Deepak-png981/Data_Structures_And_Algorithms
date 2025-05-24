class Solution {
  private:
    vector<string> computeSubstring(string &s){
        int n = s.length();
        vector<string>ans;
        for(int i = 0; i<n; i++){
            string temp = "";
            for(int j = i; j<n; j++){
                temp += s[j]; 
            // cout<<"temp : "<<temp<<endl;
            ans.push_back(temp);
            }
        }
        return ans;
    }
  public:
    int sumSubstrings(string &s) {
        vector<string> substring = computeSubstring(s);
        int sum = 0;
        for(int i = 0; i<substring.size(); i++){
            sum += stoi(substring[i]);
        }
        return sum;
        
    }
};
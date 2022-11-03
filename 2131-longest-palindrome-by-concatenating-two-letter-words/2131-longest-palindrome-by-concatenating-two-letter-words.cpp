class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        map<string , int>mp;
        for(int i = 0; i<n; i++){
            string temp = words[i];
            reverse(temp.begin() , temp.end());
            if(mp[temp] != 0){
                ans += 4;
                mp[temp]--;
            }else{
                mp[words[i]]++;
            }
        }
        
        for(int i = 0; i<n; i++){
            if(words[i][0] == words[i][1]){
                if(mp[words[i]] > 0){
                    return ans+2;
                }
            }
        }
        return ans;
        
    }
};
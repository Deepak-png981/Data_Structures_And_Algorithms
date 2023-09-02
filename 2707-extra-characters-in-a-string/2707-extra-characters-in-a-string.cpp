class Solution {
public:
    vector<int> dp;// dp[i]=the minimum extra characters needed for s[i:end]
    int n;
    int f(int i, string& s, vector<string>& dictionary) {
        if (i == n) return 0; // Base case

        if (dp[i]!= -1) return dp[i]; 
        int ans = n; 

        for (string& w : dictionary) {
            int wLen = w.size();
            if (i+wLen <= n && s.substr(i, wLen) == w) {
            // If the current word matches the substring starting at position i
                int extra = f(i+wLen, s, dictionary);
                ans = min(ans, extra);
            }
        }

        // The current character is not covered by any word in the dictionary
        int noWord = 1 + f(i+1, s, dictionary);

        // Take the minimum of using a word or not using a word
        ans = min(ans, noWord);

        return dp[i]=ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        n=s.size();
        dp.assign(n, -1); 
        return f(0, s, dictionary);
    }

};
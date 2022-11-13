class Solution
{
    public:
        string reverseWords(string s)
        {
            int i = 0;
            vector<string> v;
            int n = s.size();
            while (i < n)
            {
                string ans = "";
                
               	//ye tbhi chalega bhai jab space najar ayega
                while (i < n and s[i] == ' ') i++;
                
               	//ye tabhi chalega bhai jab space nhi najar ayega
                while (i < n and s[i] != ' ') ans += s[i++];
                
                if (ans == "" or ans == " ") 
                    continue;
                v.push_back(ans);
            }
            reverse(v.begin() , v.end());
            string res = v[0];
            for(int i = 1; i<v.size(); i++){
                res += " " + v[i];
            }
            return res;
        }
};
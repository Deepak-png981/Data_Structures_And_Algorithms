class Solution
{
    public:
        string reverseVowels(string s)
        {

            map<char, int> mp;
            mp['a']++;
            mp['e']++;
            mp['i']++;
            mp['o']++;
            mp['u']++;
            mp['A']++;
            mp['E']++;
            mp['I']++;
            mp['O']++;
            mp['U']++;
            stack<int> sk;
            for (int i = 0; i < s.size(); i++)
            {
                if (mp[s[i]] > 0)
                {
                    sk.push(s[i]);
                }
            }

            for (int i = 0; i < s.size(); i++)
            {
                if (mp[s[i]] > 0)
                {
                    s[i] = sk.top();
                    sk.pop();
                }
            }

            return s;
        }
};
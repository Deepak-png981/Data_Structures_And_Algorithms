class Solution
{
    public:
        int numPairsDivisibleBy60(vector<int> &time)
        {
            unordered_map<int, int> s;
            int cnt = 0, multi = 0;	// Using multi to keep track of multiples of 60 we have come across

            for (auto t: time)
            {
                int reduced = t % 60;
                if (reduced == 0) cnt += multi++;	// If it's a multiple, you can form a pair with every multiple seen until now
                else
                {
                    cnt += s[60 - reduced];	// Else we see how many matching pairs we can form with the difference and add that to the count
                    s[reduced]++;
                }
            }

            return cnt;
        }
};
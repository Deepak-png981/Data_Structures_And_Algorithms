class Solution
{
    public:
        int mod = 1e9 + 7;
    int maxArea(int h, int w, vector<int> &hc, vector<int> &vc)
    {
        hc.push_back(h);
        vc.push_back(w);
        sort(hc.begin(), hc.end());
        int mxh = hc[0];
        for (int i = 1; i < hc.size(); i++)
        {
            mxh = max(mxh, hc[i] - hc[i - 1]);
        }
        sort(vc.begin(), vc.end());
        int mxv = vc[0];
        for (int i = 1; i < vc.size(); i++)
        {
            mxv = max(mxv, vc[i] - vc[i - 1]);
        }
        return ( 1LL * mxh * mxv) % mod;
    }
};
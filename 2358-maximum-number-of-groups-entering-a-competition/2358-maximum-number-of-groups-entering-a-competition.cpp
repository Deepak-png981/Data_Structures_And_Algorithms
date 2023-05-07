class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n=grades.size();
        int lo=1, hi=n, mid;
        long long temp;
        int ans;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            temp= mid;
            temp*= (mid+1);
            temp/=2;
            //temp= (mid * (mid+1))/2;
            if(temp<=n)
            {
                ans=mid;
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int res = 0;
        for(int i  = 0 ; i<k; i++)
            res+=cardPoints[i];
        int currSum = res;
        for(int i = k-1; i>= 0; i--){
            //aghe se minus ker rhe hai kth element ko
            currSum = currSum - cardPoints[i];
            //peeche se add ker rhe hai last kth element ko
            currSum = currSum + cardPoints[n - k + i];
            res = max(currSum , res);
        }
        return res;
    }
};
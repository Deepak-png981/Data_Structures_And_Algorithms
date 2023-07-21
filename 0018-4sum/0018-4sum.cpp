class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        set<vector<int>>st;
        for(int i = 0; i<n; i++){
            for(int j = i + 1 ; j<n; j++){
                set<long long>hashset;
                for(int k = j + 1 ; k<n; k++){
                    long long sum = arr[i] + arr[j];
                    sum += arr[k];
                    long long fourth = target - sum;
                    if(hashset.find(fourth) != hashset.end()){
                        vector<int>temp = {arr[i] , arr[j] , arr[k], (int)fourth};
                        sort(temp.begin() , temp.end());
                        st.insert(temp);
                       
                    }
                     hashset.insert(arr[k]);
                }
            }
        }
        vector<vector<int>>ans(st.begin() , st.end());
        return ans;
    }
};
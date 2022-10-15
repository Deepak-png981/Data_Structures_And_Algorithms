class Solution {
public:
    bool isMonotonic(vector<int>& arr) {
        int n = arr.size();
        int count1 = 0 , count2 = 0;
        for(int i = 1; i<n; i++){
            if(arr[i] == arr[i-1]){
                count1++;
                count2++;
            }
            else if(arr[i-1] > arr[i])
                count1++;
            else if(arr[i-1] <arr[i])
                count2++;
        }
        // cout<<"count : "<<count2;
        if(count1 == n - 1 or count2 == n - 1)
            return true;
        return false;
    }
};
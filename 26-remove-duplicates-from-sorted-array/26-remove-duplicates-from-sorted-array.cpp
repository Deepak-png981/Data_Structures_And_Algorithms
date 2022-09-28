class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
       int n = arr.size();
       int count = 0;
        for(int i = 0 ; i<n; i++){
            if(arr[count] != arr[i])
                count++;
            arr[count] = arr[i];
        }
        return count+1;
    }
};
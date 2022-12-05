class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = needle.length();
        int n = haystack.length();
        
        for(int i = 0; i<n; i++){
            bool flag = true;
            int indx = i;
            for(int j = 0; j<h; j++){
                
                if(haystack[i+j] != needle[j]){
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                return indx;
        }
        return -1;
    }
};
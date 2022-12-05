class Solution {
public:
    bool isPalindrone(int i  , int j , string s){
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        int count = 0; //to count the points where the string is not palindrone
        while(i < j){
            if(s[i] == s[j])
            {
                i++;
                j--;
            }else{
                return (isPalindrone(i+1, j , s) or isPalindrone(i , j-1 , s));
            }
        }
        return true;
    }
};
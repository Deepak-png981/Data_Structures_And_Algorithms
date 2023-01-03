class Solution {
private:
    bool issafe(string s , string str){
        for(int i = 0; i<s.length(); i+=str.length()){
            string cs = s.substr(i , str.length());
            if(cs != str)
                return false;
        }
        return true;
    }
public:
    bool repeatedSubstringPattern(string s) {
        string str = "";
        for(int i = 0; i<s.length()/2; i++){
            str += s[i];
            if(s.length() % str.length() != 0)
            {
                continue;
            }else{
                bool res = issafe(s.substr(i+1) , str);
                if(res)
                    return true;
            }
        }
        return false;
    }
};
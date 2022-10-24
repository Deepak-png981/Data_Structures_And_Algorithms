class Solution {
public:
    int len{0};
    int maxLength(vector<string>& arr) {
        checkLen("" , arr , 0);
        return len;
    }
    void checkLen(string str , vector<string>& arr , int itr){
        if(!checkDuplicate(str))    
            return ;
        if(str.length() > len)
            len = str.length();
        for(int i = itr ; i<arr.size(); i++){
            checkLen(str + arr[i] , arr , i);
        }
            
    }
    bool checkDuplicate(string word){
        set<char> st;
        for(auto ele : word){
            if(st.find(ele) != st.end())  return false;
            st.insert(ele)
                ;
        }
        return true;
    }
};
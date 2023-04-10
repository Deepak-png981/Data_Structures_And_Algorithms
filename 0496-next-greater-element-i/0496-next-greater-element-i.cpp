class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        bool flag = false;
        for(int i = 0; i<nums1.size(); i++){
            for(int j = 0;j < nums2.size(); j++){
                if(nums1[i]==nums2[j]){
                    if(j == nums2.size()-1){
                        res.push_back(-1);
                    }else{
                        flag = false;
                        for(int k = j+1; k<nums2.size(); k++){
                            if(nums2[k] > nums2[j]){
                                flag = true;
                                res.push_back(nums2[k]);
                                break;
                            }
                        }
                        if(flag == false)
                            res.push_back(-1);
                    }
                }
            }
        }
        return res;
    }
};
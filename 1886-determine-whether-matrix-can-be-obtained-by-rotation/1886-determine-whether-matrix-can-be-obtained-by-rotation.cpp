class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target)
                    return true;
        int ptr = 3;
        while(ptr--){
            reverse(mat.begin() , mat.end());
            for(int i = 0; i<mat.size(); i++){
                for(int j = i + 1; j<mat[i].size(); j++)
                    swap(mat[i][j] , mat[j][i]);
            }
            if(mat == target)
                    return true;
        }
        return false;
    }
};
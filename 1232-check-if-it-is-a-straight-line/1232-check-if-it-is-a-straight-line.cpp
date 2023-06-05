class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        if(coordinates[1][0] - x1==0 ){
            for(int i=1; i<coordinates.size(); i++){
                if(coordinates[i][0]!=x1) return false;
            }
        }
        else{
            float slope = (float)(coordinates[1][1] - y1)/(coordinates[1][0] - x1);
            for(int i=2; i<coordinates.size(); i++){
                float s = (float)(coordinates[i][1] - y1)/(coordinates[i][0] - x1);
                if(s!=slope){
                    return false;
                }
            }
        }
        return true;
    }
};
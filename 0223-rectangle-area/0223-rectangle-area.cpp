class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int leftLength = ax2 - ax1;
        int leftHeight = ay2 - ay1;
        int leftArea = leftLength * leftHeight;
        
        int rightL = bx2 - bx1;
        int rightH = by2 - by1;
        int rightArea = rightL * rightH;
        
        int commonA = max(min(ax2,bx2) - max(ax1,bx1),0) * max(min(ay2,by2) - max(ay1,by1),0);
        return leftArea + rightArea - commonA;
    }
};
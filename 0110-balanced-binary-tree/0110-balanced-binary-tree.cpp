
class Solution {
private: 
    //in pair bool is for balanced tree checking and int is for height
    pair<bool , int> balheight(TreeNode * root){
        if(!root){
            pair<bool , int> p;
            p.first = true;
            p.second = 0;
            return p;
        }
        pair<bool , int> left = balheight(root->left);
        pair<bool , int> right = balheight(root->right);
        
        bool op1 = left.first;
        bool op2 = right.first;
        bool op3 = abs(left.second - right.second) <= 1;
        
        pair<bool , int>p;
        if(op1 and op2 and op3)
            p.first = true;
        else
            p.first = false;
        p.second = max(left.second , right.second) + 1;
        return p;
    }
public:
    bool isBalanced(TreeNode* root) {
        pair<bool , int>p = balheight(root);
        return p.first;
    }
};
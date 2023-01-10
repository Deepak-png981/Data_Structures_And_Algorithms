class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL or q == NULL )
            return p == q;
        bool cond = p->val ==  q->val;
        bool left = isSameTree(p->left , q->left);
        bool right = isSameTree(p->right , q->right);
        
        if(cond and left and right)
            return true;
        return false;
    }
};
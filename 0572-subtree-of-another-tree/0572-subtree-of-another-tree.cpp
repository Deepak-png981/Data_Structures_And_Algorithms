/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool ans = false;
    bool match(TreeNode* root, TreeNode* subroot){
        if(root != NULL and subroot != NULL){
            bool a = match(root ->left , subroot ->left);
            bool b = match(root->right , subroot->right);
            if( (root->val == subroot->val) and a and b)
                return true;
            else
                return false;
        }
        else if(root == NULL and subroot == NULL)
            return true;
        else
            return false;
    }
    void inorder(TreeNode* root, TreeNode* subroot){
        if(root != NULL){
            inorder(root->left , subroot);
            bool x = match(root , subroot);
            if(x)
                ans = x;
            inorder(root -> right , subroot);
        }
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        inorder(root , subroot);
        return ans;
    }
};
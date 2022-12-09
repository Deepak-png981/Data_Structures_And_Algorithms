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
    int res = 0;
    void helper(TreeNode* root , int mx , int mn){
        if(!root)
            return;
        if(mx != INT_MIN){
            res = max(res , abs(mx - root->val));
        }
        if(mn != INT_MAX){
            res = max(res , abs(root->val - mn));
        }
        mx = max(mx , root->val);
        mn = min(mn , root->val);
        helper(root->left , mx , mn);
        helper(root->right , mx , mn);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return res;
        int mx =  INT_MIN;
        int mn = INT_MAX;
        helper(root , mx , mn);
        return res;
    }
};
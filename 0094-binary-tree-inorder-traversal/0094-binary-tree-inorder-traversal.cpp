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
    void helper(TreeNode* root , vector<int>&ans){
        if(root->left == NULL and root->right == NULL)
        {
            ans.push_back(root->val);
             return;
        }
        if(root->left != NULL)
            helper(root->left , ans);
        ans.push_back(root->val);
        if(root->right != NULL)
            helper(root->right , ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == NULL)
            return ans;
        helper(root , ans);
        return ans;
    }
};
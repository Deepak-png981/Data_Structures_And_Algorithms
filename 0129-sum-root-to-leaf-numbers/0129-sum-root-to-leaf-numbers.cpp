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
    void dfs(TreeNode* root , int &ans , int temp){
        if(root->right == NULL and root->left == NULL){
            temp = temp * 10 + root->val;
            ans += temp;
            return;
            
        }
        temp = temp * 10 + root->val;
        if(root->right) dfs(root->right , ans , temp);
        if(root->left) dfs(root->left , ans , temp);
        
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root , ans , 0);
        return ans;
    }
};
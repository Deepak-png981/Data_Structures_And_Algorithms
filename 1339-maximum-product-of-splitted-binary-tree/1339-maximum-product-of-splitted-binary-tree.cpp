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
//approach bus ye hai ki bus sare tree ka sum nikaalo phir subtree ka nikaalte jao or compare krte jao , sabse max product ko return kro 
class Solution {
public:
    long mod = 1e9+7;
    long maxP = 0 , SUM = 0;
    int treeSum(TreeNode* root){
        if(!root)
            return 0;
        int leftSum  = treeSum(root->left);
        int rightSum = treeSum(root->right);
        int totalSum = root->val + leftSum + rightSum;
        return totalSum;
    }
    int subTreeSum(TreeNode* root){
        if(!root)
            return 0;
        int leftSum  = subTreeSum(root->left);
        int rightSum = subTreeSum(root->right);
        long totalSum = root->val + leftSum + rightSum; //s1
        long remainingSubtreeSum = SUM - totalSum;
    
        maxP = max(maxP ,totalSum*remainingSubtreeSum) ;
        return totalSum;
        
    }
    int maxProduct(TreeNode* root) {
        if(!root)
            return 0;
        SUM = treeSum(root);
        subTreeSum(root);
        return maxP%mod;
    }
};
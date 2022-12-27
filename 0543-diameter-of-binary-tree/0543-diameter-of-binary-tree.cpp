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
private:
    // in pair diameter height
    pair<int,int> heightD(TreeNode* root){
        if(root == NULL){
            pair<int , int> p ;
            p.first = 0;
            p.second = 0;
            return p;
        }
        pair<int , int>left = heightD(root->left);
        pair<int , int>right = heightD(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;
        
        pair<int, int>p;
        p.first = max(op1 , max(op2 , op3));
        p.second = max(left.second , right.second) + 1;
        return p;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int , int>ans = heightD(root);
        return ans.first;
    }
};
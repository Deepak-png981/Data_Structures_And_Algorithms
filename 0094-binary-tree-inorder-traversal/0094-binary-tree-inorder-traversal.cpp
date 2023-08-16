/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<int> inorderTraversal(TreeNode *root)
        {
            vector<int> inorder;
            TreeNode *curr = root;
            while (curr != NULL)
            {
                if (curr->left == NULL)
                {
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
                else
                {
                    TreeNode *leftiest = curr->left;
                    while (leftiest->right != NULL and leftiest->right != curr)
                    {
                        leftiest = leftiest->right;
                    }
                    if (leftiest->right == NULL)
                    {

                        leftiest->right = curr;
                        curr = curr->left;
                    }
                    else if (leftiest->right == curr)
                    {
                        inorder.push_back(curr->val);
                        leftiest->right = NULL;
                        curr = curr->right;
                    }
                }
            }
            return inorder;
        }
};
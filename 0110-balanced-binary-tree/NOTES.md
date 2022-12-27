```
//Brute force
class Solution {
private:
int height(TreeNode* root){
if(!root)
return 0;
int l = height(root->left);
int r = height(root->right);
int ans = max(l , r) + 1;
return ans;
}
public:
bool isBalanced(TreeNode* root) {
if(root == NULL){
return true;
}
bool left = isBalanced(root->left);
bool right = isBalanced(root->right);
bool diff = abs( height(root->right) - height(root->left) ) <= 1;
if(left and right and diff)
return true;
return false;
}
};
```
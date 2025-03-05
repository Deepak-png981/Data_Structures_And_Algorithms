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

//vertical order traversal : [9] [3 15] [20] [7]
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int , int>>>q; //node and the x&y
        map<int,map<int, multiset<int>>>mp; //x and y -> val (sorted)
        vector<vector<int>>ans;
        q.push({root, {0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* front = it.first;
            int x = it.second.first;
            int y = it.second.second;
            mp[x][y].insert(front->val);
            
            if(front->left)
                q.push({front->left , {x-1, y+1}});
            if(front -> right)
                q.push({front->right , {x+1 , y+1}});
        }
        for(auto p : mp){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(), q.second.begin() , q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
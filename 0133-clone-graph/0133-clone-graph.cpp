/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node* , Node*>mp;
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;
        Node* newnode = new Node(node->val , {});
        mp[node] = newnode;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* frontnode = q.front();
            q.pop();
            for(auto adj : frontnode -> neighbors){
                if(!mp[adj]){
                    mp[adj] = new Node(adj->val , {});
                    q.push(adj);
                }
                mp[frontnode] -> neighbors.push_back(mp[adj]);
            }
        }
        return mp[node];
    }
};
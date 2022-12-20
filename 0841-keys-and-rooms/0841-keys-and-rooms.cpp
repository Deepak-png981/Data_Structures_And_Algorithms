class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n , 0);
        queue<int>q;
        q.push(0);
        vis[0] = true;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto it : rooms[front]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        for(auto it : vis){
            if(it == 0)
                return false;
        }
        return true;
    }
};
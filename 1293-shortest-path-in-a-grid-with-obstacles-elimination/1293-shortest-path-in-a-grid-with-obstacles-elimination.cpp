class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int m = grid.size(), n = grid[0].size();
        // [1] this check significantly improves runtime, i.e.,
        //    we can use path [0,0] -> [0,n-1] -> [m-1,n-1]
        if (k >= m + n - 2) return m + n - 2;
        
        // [2] we use deque to store and update a BFS state that is
        //    (x, y, obstacles we can destroy, steps done so far)
        deque<vector<int>> dq;
        dq.push_back({0,0,k,0});
        // [3] we also keep track of visited cells
        set<vector<int>> seen;
        
        vector<pair<int,int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!dq.empty())
        {
            vector<int> p = dq.front(); dq.pop_front();
            int i = p[0], j = p[1], k = p[2], s = p[3];
            // [4] successfully reached lower right corner
            if (i == m-1 && j == n-1) return s;
            
            // [5] scan all possible directions
            for (auto d : dirs)
            {
                int ii = i + d.first, jj = j + d.second;
                // [6] check boundaries and obstacles
                if (0 <= ii && ii < m && 0 <= jj && jj < n && k >= grid[ii][jj])
                {
                    // [7] make (and remember) a step
                    vector<int> step = {ii, jj, k-grid[ii][jj]};
                    if (seen.count(step) == 0) // in C++20, there is 'map::contains()'
                    {
                        seen.insert(step);
                        step.push_back(s+1);
                        dq.push_back(step);
                    }
                }
            }
        }
        
        // [8] failed to reach lower right corner
        return -1;
    }
};
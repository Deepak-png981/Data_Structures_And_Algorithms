class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
         size_t n = img1.size();
        
        // [1] first, we list coordinates (x,y) of 1-points in each image
        
        vector<pair<int32_t,int32_t>> idx1, idx2;
        
        for (int i = 0; i < n*n; i++)
            if (img1[i/n][i%n]) idx1.emplace_back(i/n, i%n);

        for (int j = 0; j < n*n; j++)
            if (img2[j/n][j%n]) idx2.emplace_back(j/n, j%n);
                
        // [2] second, we obtain translation vectors (i1-j1, i2-j2) needed to
        //    overlap each 1-point of img1 with each 1-point of img2, and count
        //    frequencies of these vectors;
        //    (note that here we make a 'flat' 2d array in order to use
        //    iterator-based max_element function later to find maximum)
        
        vector<int> tr_vecs(2*n * 2*n, 0);
        size_t vx, vy;
        for (auto [i1,i2] : idx1)
            for (auto [j1,j2] : idx2)
            {
                vx = (2*n+i1-j1) % (2*n);
                vy = (2*n+i2-j2) % (2*n);
                tr_vecs[vx*(2*n) + vy] += 1;
            }
        
        // [3] translation vector that has been encountered most of the time is
        //    the one that produces an overlap of the maximal number of points
        
        return *max_element(tr_vecs.begin(), tr_vecs.end());

    
    }
};
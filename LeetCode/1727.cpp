class Solution {
public:
    int largestSubmatrix(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> heights(h);
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (y && a[y][x])
                    a[y][x] += a[y - 1][x];
                
                heights[y].push_back(a[y][x]);
            }            
            sort(heights[y].begin(), heights[y].end());            
        }
        
        int res = 0;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                int curHeight = a[y][x];
                int curWidth = heights[y].end() - lower_bound(heights[y].begin(), heights[y].end(), a[y][x]);
                res = max(res, curHeight * curWidth);
            }
        }
        return res;
    }
};
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        vector<int> d(h + w, -1);
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (d[y - x + w] != -1 && d[y - x + w] != a[y][x])
                    return 0;
                d[y - x + w] = a[y][x];
            }
        }
        
        return 1;
    }
};
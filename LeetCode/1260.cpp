class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &a, int k) {
        int h = a.size(), w = a[0].size();
        k %= h * w;
        
        vector<int> values(h * w);
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                values[y * w + x] = a[y][x];
        
        rotate(values.begin(), values.end() - k, values.end());
        
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                a[y][x] = values[y * w + x];
        return a;
    }
};
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        vector<vector<int>> res(w, vector<int>(h));
        
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                res[x][y] = a[y][x];
        
        return res;
    }
};
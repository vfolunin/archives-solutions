class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        vector<int> res(w);

        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                res[x] = max<int>(res[x], to_string(a[y][x]).size());
        
        return res;
    }
};
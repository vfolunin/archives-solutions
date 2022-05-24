class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int h, int w, int cy, int cx) {
        vector<vector<int>> res;
        for (int y = 0; y < h; y++)
            for (int x = 0; x < w; x++)
                res.push_back({ y, x });
        
        sort(res.begin(), res.end(), [&](auto &a, auto &b) {
            return abs(a[0] - cy) + abs(a[1] - cx) < abs(b[0] - cy) + abs(b[1] - cx);
        });
        return res;
    }
};
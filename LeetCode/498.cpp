class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        vector<deque<int>> diags(h + w - 1);
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                int d = y + x;
                if (d % 2)
                    diags[d].push_back(a[y][x]);
                else
                    diags[d].push_front(a[y][x]);
            }
        }
        
        vector<int> res;
        for (auto &diag : diags)
            res.insert(res.end(), diag.begin(), diag.end());
        return res;
    }
};
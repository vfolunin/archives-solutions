class Solution {
public:
    int kthLargestValue(vector<vector<int>> &p, int k) {
        int h = p.size(), w = p[0].size();
        vector<int> res;
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (y)
                    p[y][x] ^= p[y - 1][x];
                if (x)
                    p[y][x] ^= p[y][x - 1];
                if (y && x)
                    p[y][x] ^= p[y - 1][x - 1];
                res.push_back(p[y][x]);
            }
        }
        
        k = h * w - k;
        nth_element(res.begin(), res.begin() + k, res.end());
        return res[k];
    }
};
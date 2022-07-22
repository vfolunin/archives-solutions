class Solution {    
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        
        vector<vector<int>> res;
        
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (a[y][x] && (!y || !a[y - 1][x]) && (!x || !a[y][x - 1])) {
                    res.push_back({ y, x, y, x });
                    vector<int> &r = res.back();
                    while (r[2] + 1 < h && a[r[2] + 1][x])
                        r[2]++;
                    while (r[3] + 1 < w && a[y][r[3] + 1])
                        r[3]++;
                }
            }
        }
        
        return res;
    }
};
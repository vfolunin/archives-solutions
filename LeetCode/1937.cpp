class Solution {
public:
    long long maxPoints(vector<vector<int>> &a) {
        int h = a.size(), w = a[0].size();
        vector<long long> res = { a[0].begin(), a[0].end() };
        
        for (int y = 1; y < h; y++) {
            vector<long long> l(w);
            l[0] = res[0];
            for (int x = 1; x < w; x++)
                l[x] = max(l[x - 1] - 1, res[x]);
            
            vector<long long> r(w);
            r[w - 1] = res[w - 1];
            for (int x = w - 2; x >= 0; x--)
                r[x] = max(r[x + 1] - 1, res[x]);
            
            for (int x = 0; x < w; x++)
                res[x] = a[y][x] + max(l[x], r[x]);
        }
        
        return *max_element(res.begin(), res.end());
    }
};
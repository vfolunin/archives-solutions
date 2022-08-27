class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>> &a, int limit) {
        int h = a.size(), w = a[0].size();
        
        for (int y = 1; y < h; y++)
            for (int x = 0; x < w; x++)
                a[y][x] += a[y - 1][x];
        
        int res = -1e9;
        
        for (int y1 = 0; y1 < h; y1++) {
            for (int y2 = y1; y2 < h; y2++) {
                int prefixSum = 0;
                set<int> prefixSums = { 0 };
                
                for (int x = 0; x < w; x++) {
                    prefixSum += a[y2][x] - (y1 ? a[y1 - 1][x] : 0);
                    
                    auto it = prefixSums.lower_bound(prefixSum - limit);
                    if (it != prefixSums.end())
                        res = max(res, prefixSum - *it);
                    
                    prefixSums.insert(prefixSum);
                }
            }
        }
        
        return res;
    }
};
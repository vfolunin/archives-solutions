class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>> &p, int target) {
        for (int y = 1; y < p.size(); y++)
            for (int x = 0; x < p[0].size(); x++)
                p[y][x] += p[y - 1][x];
        
        int res = 0;
        
        for (int y1 = 0; y1 < p.size(); y1++) {
            for (int y2 = y1; y2 < p.size(); y2++) {
                unordered_map<int, int> seen = { { 0, 1 } };
                
                int sum = 0;
                for (int x = 0; x < p[0].size(); x++) {
                    sum += p[y2][x] - (y1 ? p[y1 - 1][x] : 0);
                    if (seen.count(sum - target))
                        res += seen[sum - target];
                    seen[sum]++;
                }
            }
        }
        
        return res;
    }
};
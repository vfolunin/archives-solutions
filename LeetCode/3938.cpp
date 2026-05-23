class Solution {
public:
    int maxScore(vector<vector<int>> &a) {
        int res = -1e9;

        for (int y = 1; y + 1 < a.size(); y++)
            for (int x = 1; x + 1 < a[0].size(); x++)
                res = max(res, a[y][x]);

        for (int y = 0; y < a.size(); y++) {
            vector<int> prefixSum(a[0].size());
            for (int x = 0; x < a[0].size(); x++)
                prefixSum[x] = a[y][x] + (x ? prefixSum[x - 1] : 0);
            
            int minPrefixSum = 0;
            for (int x = 1; x < a[0].size(); x++) {
                res = max(res, prefixSum[x] - minPrefixSum);
                minPrefixSum = min(minPrefixSum, prefixSum[x - 1]);
            }
        }
        
        for (int x = 0; x < a[0].size(); x++) {
            vector<int> prefixSum(a.size());
            for (int y = 0; y < a.size(); y++)
                prefixSum[y] = a[y][x] + (y ? prefixSum[y - 1] : 0);
            
            int minPrefixSum = 0;
            for (int y = 1; y < a.size(); y++) {
                res = max(res, prefixSum[y] - minPrefixSum);
                minPrefixSum = min(minPrefixSum, prefixSum[y - 1]);
            }
        }

        return res;
    }
};
class Solution {
public:
    int countOfPairs(vector<int> &a) {
        const int MOD = 1e9 + 7;

        vector<vector<int>> ways(a.size(), vector<int>(1001));
        vector<vector<int>> waysSum(a.size(), vector<int>(1001));

        for (int last = 0; last <= a[0]; last++) {
            ways[0][last] = 1;
            waysSum[0][last] = (ways[0][last] + (last ? waysSum[0][last - 1] : 0)) % MOD;
        }

        for (int i = 1; i < a.size(); i++) {
            for (int last = 0; last <= a[i]; last++) {
                int limit = min(last, a[i - 1] - a[i] + last);
                if (limit >= 0) {
                    ways[i][last] = waysSum[i - 1][limit];
                    waysSum[i][last] = (ways[i][last] + (last ? waysSum[i][last - 1] : 0)) % MOD;
                }
            }
        }

        int res = 0;
        for (int last = 0; last <= a.back(); last++)
            res = (res + ways[a.size() - 1][last]) % MOD;
        return res;
    }
};
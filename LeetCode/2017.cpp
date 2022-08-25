class Solution {
public:
    long long gridGame(vector<vector<int>> &a) {
        long long sum0 = accumulate(a[0].begin(), a[0].end(), 0LL);
        long long sum1 = 0;
        long long res = 1e18;
        
        for (int i = 0; i < a[0].size(); i++) {
            sum0 -= a[0][i];
            res = min(res, max(sum0, sum1));
            sum1 += a[1][i];
        }
        
        return res;
    }
};
class Solution {
public:
    int xorAfterQueries(vector<int> &a, vector<vector<int>> &queries) {
        const int MOD = 1e9 + 7;
        for (vector<int> &query : queries)
            for (int i = query[0]; i <= query[1]; i += query[2])
                a[i] = (1LL * a[i] * query[3]) % MOD;
        
        int res = 0;
        for (int &value : a)
            res ^= value;
        return res;
    }
};
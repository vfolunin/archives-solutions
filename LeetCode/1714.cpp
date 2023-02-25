class Solution {
public:
    vector<int> solve(vector<int> &a, vector<vector<int>> &queries) {
        const int MOD = 1e9 + 7;
        int root = sqrt(a.size());

        vector<vector<int>> sum(root, vector<int>(a.size()));
        for (int d = 1; d < root; d++) {
            for (int i = a.size() - 1; i >= 0; i--) {
                sum[d][i] = a[i];
                if (i + d < a.size())
                    sum[d][i] = (sum[d][i] + sum[d][i + d]) % MOD;
            }
        }

        vector<int> res(queries.size());
        for (int i = 0; i < res.size(); i++) {
            if (queries[i][1] < root) {
                res[i] = sum[queries[i][1]][queries[i][0]];
            } else {
                for (int j = queries[i][0]; j < a.size(); j += queries[i][1])
                    res[i] = (res[i] + a[j]) % MOD;
            }
        }
        return res;
    }
};
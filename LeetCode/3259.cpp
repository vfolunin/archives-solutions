class Solution {
public:
    long long maxEnergyBoost(vector<int> &a, vector<int> &b) {
        vector<vector<long long>> res(a.size(), vector<long long>(2));
        res[0] = { a[0], b[0] };
        res[1] = { a[0] + a[1], b[0] + b[1] };

        for (int i = 2; i < res.size(); i++) {
            res[i][0] = max(res[i - 1][0], res[i - 2][1]) + a[i];
            res[i][1] = max(res[i - 1][1], res[i - 2][0]) + b[i];
        }

        return max(res.back()[0], res.back()[1]);
    }
};
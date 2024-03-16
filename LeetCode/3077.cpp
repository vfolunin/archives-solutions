class Solution {
public:
    long long maximumStrength(vector<int> &a, int partCount) {
        vector<vector<vector<long long>>> res(a.size(), vector<vector<long long>>(partCount + 1, vector<long long>(2, -1e18)));

        res[0][0][0] = 0;
        res[0][1][1] = 1LL * a[0] * partCount;

        for (int i = 1; i < a.size(); i++) {
            res[i][0][0] = res[i - 1][0][0];
            for (int parts = 1; parts <= partCount; parts++) {
                res[i][parts][0] = max(res[i - 1][parts][0], res[i - 1][parts][1]);
                res[i][parts][1] = max({ res[i - 1][parts - 1][0], res[i - 1][parts - 1][1], res[i - 1][parts][1] }) +
                                   1LL * a[i] * (partCount - parts + 1) * (parts % 2 ? 1 : -1);
            }
        }

        return max(res[a.size() - 1][partCount][0], res[a.size() - 1][partCount][1]);
    }
};
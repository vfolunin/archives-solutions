class Solution {
public:
    int maxProfit(vector<int> &a) {
        vector<vector<int>> res(a.size() + 1, vector<int>(4, -1e9));
        res[0][0] = -a[0];

        for (int i = 1; i < a.size(); i++) {
            res[i][0] = max(res[i - 1][0], -a[i]);
            res[i][1] = max(res[i - 1][1], res[i - 1][0] + a[i]);
            res[i][2] = max(res[i - 1][2], res[i - 1][1] - a[i]);
            res[i][3] = max(res[i - 1][3], res[i - 1][2] + a[i]);
        }

        return max({ 0, res[a.size() - 1][1], res[a.size() - 1][3] });
    }
};
class Solution {
    int solve(vector<int> &a, int sum) {
        vector<vector<int>> res(a.size(), vector<int>(a.size()));
        for (int len = 2; len <= a.size(); len++) {
            for (int l = 0, r = len - 1; r < a.size(); l++, r++) {
                if (a[l] + a[l + 1] == sum)
                    res[l][r] = max(res[l][r], (l + 2 < a.size() ? res[l + 2][r] : 0) + 1);
                if (a[r - 1] + a[r] == sum)
                    res[l][r] = max(res[l][r], (r >= 2 ? res[l][r - 2] : 0) + 1);
                if (a[l] + a[r] == sum)
                    res[l][r] = max(res[l][r], res[l + 1][r - 1] + 1);
            }
        }
        return res[0][a.size() - 1];
    }

public:
    int maxOperations(vector<int> &a) {
        return max({ solve(a, a[0] + a[1]), solve(a, a[a.size() - 2] + a[a.size() - 1]), solve(a, a[0] + a[a.size() - 1]) });
    }
};
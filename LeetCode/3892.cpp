class Solution {
    bool isPeak(const vector<int> &a, int i) {
        int l = (i + a.size() - 1) % a.size();
        int r = (i + 1) % a.size();
        return a[l] < a[i] && a[i] > a[r];
    }

    int opsToPeak(const vector<int> &a, int i) {
        int l = (i + a.size() - 1) % a.size();
        int r = (i + 1) % a.size();
        return max(max(a[l], a[r]) - a[i] + 1, 0);
    }

    int solve(const vector<int> &a, int minPeaks, vector<vector<int>> &ops) {
        for (int i = 2; i < ops.size(); i++) {
            if (!isPeak(a, i))
                ops[i][0] = ops[i - 1][0];
            for (int peaks = 1; peaks <= i + 1; peaks++)
                ops[i][peaks] = min(ops[i - 1][peaks], ops[i - 2][peaks - 1] + opsToPeak(a, i));
        }

        return *min_element(ops.back().begin() + minPeaks, ops.back().end());
    }

    int solve00(const vector<int> &a, int minPeaks, vector<vector<int>> &ops) {
        if (isPeak(a, 0) || isPeak(a, a.size() - 1))
            return 1e9;

        ops.assign(a.size() - 1, vector<int>(a.size(), 1e9));
        ops[0][0] = 0;
        if (a.size() > 2) {
            if (!isPeak(a, 1))
                ops[1][0] = 0;
            ops[1][1] = opsToPeak(a, 1);
        }
        return solve(a, minPeaks, ops);
    }

    int solve10(const vector<int> &a, int minPeaks, vector<vector<int>> &ops) {
        ops.assign(a.size() - 1, vector<int>(a.size(), 1e9));
        ops[0][1] = opsToPeak(a, 0);
        if (a.size() > 2)
            ops[1][1] = ops[0][1];
        return solve(a, minPeaks, ops);
    }

public:
    int minOperations(vector<int> &a, int minPeaks) {
        if (minPeaks >= a.size())
            return -1;

        vector<vector<int>> ops;
        int res = min({ solve00(a, minPeaks, ops), solve10(a, minPeaks, ops), solve10({ a.rbegin(), a.rend() }, minPeaks, ops) });
        return res != 1e9 ? res : -1;
    }
};
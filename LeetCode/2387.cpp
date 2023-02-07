class Solution {
    bool can(vector<vector<int>> &a, int value) {
        int count = 0;
        for (vector<int> &row : a)
            count += row.end() - upper_bound(row.begin(), row.end(), value);
        return count > a.size() * a[0].size() / 2;
    }

public:
    int matrixMedian(vector<vector<int>> &a) {
        int l = 0, r = 1e6 + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, m))
                l = m;
            else
                r = m;
        }
        return r;
    }
};
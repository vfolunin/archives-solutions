class Solution {
    bool can(vector<int> &a, vector<vector<int>> &queries, int m) {
        vector<int> deltas(a.size() + 1);
        for (int i = 0; i < m; i++) {
            deltas[queries[i][0]] += queries[i][2];
            deltas[queries[i][1] + 1] -= queries[i][2];
        }

        int totalDelta = 0;
        for (int i = 0; i < a.size(); i++) {
            totalDelta += deltas[i];
            if (a[i] > totalDelta)
                return 0;
        }
        return 1;
    }

public:
    int minZeroArray(vector<int> &a, vector<vector<int>> &queries) {
        int l = -1, r = queries.size() + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(a, queries, m))
                r = m;
            else
                l = m;
        }
        return r != queries.size() + 1 ? r : -1;
    }
};

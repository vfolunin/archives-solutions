class Solution {
    int getQueryCount(int index, int targetValue, vector<vector<int>> &queries) {
        if (!targetValue)
            return 0;

        vector<int> can(targetValue + 1);
        can[0] = 1;

        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] <= index && index <= queries[i][1])
                for (int value = targetValue; value >= queries[i][2]; value--)
                    can[value] |= can[value - queries[i][2]];

            if (can[targetValue])
                return i + 1;
        }

        return queries.size() + 1;
    }

public:
    int minZeroArray(vector<int> &a, vector<vector<int>> &queries) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            res = max(res, getQueryCount(i, a[i], queries));
        return res <= queries.size() ? res : -1;
    }
};
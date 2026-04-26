class Solution {
    int lessCount(vector<int> &a, int from, int to, int value) {
        int l = -1, r = to - from;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (a[from + m] < value)
                l = m;
            else
                r = m;
        }
        return r;
    }

    bool has(vector<int> &a, int from, int to, int value) {
        return binary_search(a.begin() + from, a.begin() + to, value);
    }

    bool can(vector<int> &evenValues, int from, int to, int targetIndex, int value) {
        int index = value / 2 - lessCount(evenValues, from, to, value);
        return index > targetIndex || index == targetIndex && !has(evenValues, from, to, value);
    }

public:
    vector<int> kthRemainingInteger(vector<int> &values, vector<vector<int>> &queries) {
        vector<int> evenValues;
        for (int value : values)
            if (value % 2 == 0)
                evenValues.push_back(value);

        vector<int> res;
        for (vector<int> &query : queries) {
            int from = lower_bound(evenValues.begin(), evenValues.end(), values[query[0]]) - evenValues.begin();
            int to = upper_bound(evenValues.begin(), evenValues.end(), values[query[1]]) - evenValues.begin();
            int index = query[2];

            long long l = -1, r = 1.1e9;
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (can(evenValues, from, to, index, m * 2))
                    r = m;
                else
                    l = m;
            }
            res.push_back(r * 2);
        }
        return res;
    }
};
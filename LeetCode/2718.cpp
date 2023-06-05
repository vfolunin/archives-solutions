class Solution {
public:
    long long matrixSumQueries(int size, vector<vector<int>> &queries) {
        int h = size, w = size;
        unordered_set<int> rows, cols;
        long long res = 0;

        for (int i = queries.size() - 1; i >= 0; i--) {
            if (queries[i][0]) {
                if (!cols.count(queries[i][1])) {
                    cols.insert(queries[i][1]);
                    res += h * queries[i][2];
                    w--;
                }
            } else {
                if (!rows.count(queries[i][1])) {
                    rows.insert(queries[i][1]);
                    res += w * queries[i][2];
                    h--;
                }
            }
        }

        return res;
    }
};
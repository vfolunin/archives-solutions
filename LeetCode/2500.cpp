class Solution {
public:
    int deleteGreatestValue(vector<vector<int>> &a) {
        for (auto &row : a)
            sort(row.begin(), row.end());

        int res = 0;
        for (int x = 0; x < a[0].size(); x++) {
            int minValue = a[0][x];
            for (int y = 1; y < a.size(); y++)
                minValue = max(minValue, a[y][x]);
            res += minValue;
        }

        return res;
    }
};
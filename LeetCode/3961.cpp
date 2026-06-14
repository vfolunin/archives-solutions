class Solution {
public:
    long long maxRatings(vector<vector<int>> &a) {
        long long res = 0;
        if (a[0].size() == 1) {
            for (vector<int> &row : a)
                res += row[0];
            return res;
        }

        int min0 = 1e9, min1 = 1e9;
        for (vector<int> &row : a) {
            sort(row.begin(), row.end());
            res += row[1];
            min0 = min(min0, row[0]);
            min1 = min(min1, row[1]);
        }
        res += min0 - min1;
        return res;
    }
};
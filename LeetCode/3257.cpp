class Solution {
    vector<pair<int, int>> getMax3(vector<int> &row) {
        set<pair<int, int>> values;
        for (int i = 0; i < row.size(); i++) {
            values.insert({ row[i], i });
            if (values.size() > 3)
                values.erase(values.begin());
        }
        return { values.begin(), values.end() };
    }

    long long getMaxSum(const vector<pair<int, int>> &a, const vector<pair<int, int>> &b, const vector<pair<int, int>> &c) {
        long long res = -1e18;
        for (auto &[aValue, ai] : a)
            for (auto &[bValue, bi] : b)
                for (auto &[cValue, ci] : c)
                    if (ai != bi && ai != ci && bi != ci)
                        res = max(res, (long long)aValue + bValue + cValue);
        return res;
    }

public:
    long long maximumValueSum(vector<vector<int>> &a) {
        vector<vector<int>> l = a;
        for (int y = 1; y < a.size(); y++)
            for (int x = 0; x < a[0].size(); x++)
                l[y][x] = max(l[y][x], l[y - 1][x]);
        
        vector<vector<int>> r = a;
        for (int y = a.size() - 2; y >= 0; y--)
            for (int x = 0; x < a[0].size(); x++)
                r[y][x] = max(r[y][x], r[y + 1][x]);
        
        long long res = -1e18;
        for (int y = 1; y + 1 < a.size(); y++)
            res = max(res, getMaxSum(getMax3(l[y - 1]), getMax3(a[y]), getMax3(r[y + 1])));
        return res;
    }
};
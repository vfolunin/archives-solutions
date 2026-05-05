class Solution {
public:
    vector<int> minCost(vector<int> &a, vector<vector<int>> &queries) {
        vector<long long> pl(a.size());
        for (int i = a.size() - 1; i; i--) {
            pl[i] = i == a.size() - 1 || a[i] - a[i - 1] <= a[i + 1] - a[i] ? 1 : a[i] - a[i - 1];
            if (i < a.size() - 1)
                pl[i] += pl[i + 1];
        }
        
        vector<long long> pr(a.size());
        for (int i = 0; i + 1 < a.size(); i++) {
            pr[i] = !i || a[i] - a[i - 1] > a[i + 1] - a[i] ? 1 : a[i + 1] - a[i];
            if (i)
                pr[i] += pr[i - 1];
        }

        vector<int> res(queries.size());
        for (int i = 0; i < res.size(); i++) {
            int l = queries[i][0], r = queries[i][1];
            if (l < r)
                res[i] = pr[r - 1] - (l ? pr[l - 1] : 0);
            else if (l > r)
                res[i] = pl[r + 1] - (l < a.size() - 1 ? pl[l + 1] : 0);
        }
        return res;
    }
};
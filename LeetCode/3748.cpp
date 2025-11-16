class Solution {
    long long getSum(long long size) {
        if (size <= 0)
            return 0;
        return size * (size + 1) / 2;
    }

    long long getSum(vector<long long> &p, int l, int r) {
        if (l > r)
            return 0;
        return p[r] - (l ? p[l - 1] : 0);
    }

public:
    vector<long long> countStableSubarrays(vector<int> &a, vector<vector<int>> &queries) {
        vector<int> stableSize(a.size(), 1);
        for (int i = 1; i < stableSize.size(); i++)
            if (a[i - 1] <= a[i])
                stableSize[i] += stableSize[i - 1];
        
        vector<long long> pStableSize(stableSize.begin(), stableSize.end());
        partial_sum(pStableSize.begin(), pStableSize.end(), pStableSize.begin());

        vector<long long> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1] + 1;
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (m - stableSize[m] + 1 < queries[i][0])
                    l = m;
                else
                    r = m;
            }

            res[i] = getSum(l - queries[i][0] + 1) + getSum(pStableSize, r, queries[i][1]);
        }
        return res;
    }
};
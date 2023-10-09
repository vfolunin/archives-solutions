class Solution {
    long long getSum(vector<long long> &p, int l, int r) {
        if (l > r)
            return 0;
        return p[r] - (l ? p[l - 1] : 0);
    }
    
    long long getLoss(vector<int> &a, vector<long long> &p, int limit, long long smallCount, long long largeCount) {
        long long delta = largeCount * limit;
        long long aliceCost = getSum(p, a.size() - largeCount, a.size() - 1) - delta;
        long long bobCost = getSum(p, 0, smallCount - 1) + delta;
        return bobCost - aliceCost;
    }

    long long getLoss(vector<int> &a, vector<long long> &p, int limit, int count) {
        int l = 0, r = min<int>(upper_bound(a.begin(), a.end(), limit) - a.begin(), count);
        while (l + 5 < r) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            if (getLoss(a, p, limit, m1, count - m1) < getLoss(a, p, limit, m2, count - m2))
                r = m2;
            else
                l = m1;
        }
        
        long long loss = 1e18;
        for (int i = l; i <= r; i++)
            loss = min(loss, getLoss(a, p, limit, i, count - i));
        return loss;
    }

public:
    vector<long long> minimumRelativeLosses(vector<int> &a, vector<vector<int>> &queries) {
        sort(a.begin(), a.end());

        vector<long long> p(a.begin(), a.end());
        partial_sum(p.begin(), p.end(), p.begin());

        vector<long long> res(queries.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = getLoss(a, p, queries[i][0], queries[i][1]);
        return res;
    }
};
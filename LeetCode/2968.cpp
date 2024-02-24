class Solution {
    long long getSum(vector<long long> &p, int l, int r) {
        if (l > r)
            return 0;
        return p[r] - (l ? p[l - 1] : 0);
    }

    long long ops(vector<long long> &p, int l, int r) {
        int m = l + (r - l) / 2;
        long long value = getSum(p, m, m);
        long long leftOps = value * (m - l + 1) - getSum(p, l, m);
        long long rightOps = getSum(p, m + 1, r) - value * (r - m);
        return leftOps + rightOps;
    }

    bool can(vector<long long> &p, int len, long long limit) {
        for (int l = 0, r = len - 1; r < p.size(); l++, r++)
            if (ops(p, l, r) <= limit)
                return 1;
        return 0;
    }

public:
    int maxFrequencyScore(vector<int> &a, long long limit) {
        sort(a.begin(), a.end());
        vector<long long> p = { a.begin(), a.end() };
        partial_sum(p.begin(), p.end(), p.begin());

        int l = 0, r = a.size() + 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(p, m, limit))
                l = m;
            else
                r = m;
        }
        return l;
    }
};
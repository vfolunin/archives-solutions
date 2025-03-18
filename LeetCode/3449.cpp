class Solution {
    bool can(vector<int> &a, long long limit, long long targetValue) {
        long long overOps = 0, totalOps = 0;

        for (int i = 0; i < a.size(); i++) {
            long long ops = max((targetValue + a[i] - 1) / a[i] - overOps, 0LL);
            if (!ops && i + 1 < a.size())
                ops = 1;
            overOps = max(ops - 1, 0LL);
            totalOps += ops + overOps;

            if (totalOps > limit)
                return 0;
        }

        return 1;
    }

public:
    long long maxScore(vector<int> &a, int limit) {
        long long l = 0, r = 1;
        while (can(a, limit, r))
            r *= 2;
        
        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (can(a, limit, m))
                l = m;
            else
                r = m;
        }

        return l;
    }
};
class Solution {
    pair<int, int> rec(int mask, int last, vector<int> &a, vector<vector<pair<int, int>>> &memo) {
        pair<int, int> &res = memo[mask][last];
        if (res.first != -1)
            return res;
        
        if (mask == (1 << a.size()) - 1)
            return res = { abs(last - a[0]), 0 };
        
        res.first = 1e9;
        for (int next = 0; next < a.size(); next++) {
            if (mask & (1 << next))
                continue;

            auto [cost, _] = rec(mask | (1 << next), next, a, memo);
            cost += abs(last - a[next]);

            if (res.first > cost)
                res = { cost, next };
        }
        
        return res;
    }

public:
    vector<int> findPermutation(vector<int> &a) {
        vector memo(1 << a.size(), vector(a.size(), pair<int, int> { -1, -1 }));
        int bestCost = 1e9, bestLast;

        vector<int> certificate(a.size());
        for (int i = 0, mask = 1, last = 0; i < certificate.size(); i++) {
            certificate[i] = last;
            last = rec(mask, last, a, memo).second;
            mask |= 1 << last;
        }
        return certificate;
    }
};
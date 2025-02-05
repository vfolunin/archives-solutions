class Solution {
    long long rec(vector<int> &a, vector<int> &b, int i, int mask, vector<vector<long long>> &memo) {
        if (!mask)
            return 0;
        if (i == a.size())
            return 1e9;

        long long &res = memo[i][mask];
        if (res != -1)
            return res;

        res = rec(a, b, i + 1, mask, memo);

        for (int submask = 1; submask <= mask; submask++) {
            if ((mask & submask) != submask)
                continue;
            
            long long multiple = 1;
            for (int bit = 0; bit < b.size(); bit++)
                if (submask & (1 << bit))
                    multiple = lcm(multiple, b[bit]);

            multiple = (a[i] + multiple - 1) / multiple * multiple;
            res = min(res, multiple - a[i] + rec(a, b, i + 1, mask ^ submask, memo));
        }

        return res;
    }

public:
    int minimumIncrements(vector<int> &a, vector<int> &b) {
        vector<vector<long long>> memo(a.size(), vector<long long>(1 << b.size(), -1));
        return rec(a, b, 0, (1 << b.size()) - 1, memo);
    }
};
class Solution {
    long long rec(vector<vector<int>> &a, int mask, vector<int> &size, vector<int> &median, vector<long long> &memo) {
        long long &res = memo[mask];
        if (res != 1e18)
            return res;
        
        if (!(mask & (mask - 1)))
            return res = 0;

        for (int submask = mask & (mask - 1); submask; submask = (submask - 1) & mask)
            res = min(res, rec(a, submask, size, median, memo) + rec(a, mask ^ submask, size, median, memo) +
                               size[submask] + size[mask ^ submask] + abs(median[submask] - median[mask ^ submask]));
        return res;
    }

public:
    long long minMergeCost(vector<vector<int>> &a) {
        vector<int> size(1 << a.size());
        vector<int> median(1 << a.size());

        for (int mask = 1; mask < (1 << a.size()); mask++) {
            vector<int> values;
            for (int bit = 0; bit < a.size(); bit++)
                if (mask & (1 << bit))
                    values.insert(values.end(), a[bit].begin(), a[bit].end());
            
            size[mask] = values.size();
            nth_element(values.begin(), values.begin() + (values.size() - 1) / 2, values.end());
            median[mask] = values[(values.size() - 1) / 2];
        }

        vector<long long> memo(1 << a.size(), 1e18);
        return rec(a, (1 << a.size()) - 1, size, median, memo);
    }
};
class Solution {
    int rec(string &a, string &b, int ai, int bi, vector<int> &indices, vector<vector<int>> &memo) {
        if (bi == b.size())
            return 0;
        if (ai == a.size())
            return 1e9;

        int &res = memo[ai][bi];
        if (res != -1)
            return res;
        
        res = rec(a, b, ai + 1, bi, indices, memo);
        if (a[ai] == b[bi])
            res = min(res, rec(a, b, ai + 1, bi + 1, indices, memo) + binary_search(indices.begin(), indices.end(), ai));
        return res;
    }

public:
    int maxRemovals(string &a, string &b, vector<int> &indices) {
        vector<vector<int>> memo(a.size(), vector<int>(b.size(), -1));
        return indices.size() - rec(a, b, 0, 0, indices, memo);
    }
};
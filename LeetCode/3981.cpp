class Solution {
    const int MOD = 1e9 + 7;

    int rec(string &a, string &b, string &c, int ai, int bi, int ci, vector<vector<vector<int>>> &memo) {
        int &res = memo[ai][bi][ci];
        if (res != -1)
            return res;

        if (ci == c.size())
            return res = ai && bi;
        if (ai == a.size() && bi == b.size())
            return res = 0;

        res = 0;
        for (int i = ai; i < a.size(); i++)
            if (a[i] == c[ci])
                res = (res + rec(a, b, c, i + 1, bi, ci + 1, memo)) % MOD;
        for (int i = bi; i < b.size(); i++)
            if (b[i] == c[ci])
                res = (res + rec(a, b, c, ai, i + 1, ci + 1, memo)) % MOD;
        return res;
    }

public:
    int interleaveCharacters(string &a, string &b, string &c) {
        vector memo(a.size() + 1, vector(b.size() + 1, vector<int>(c.size() + 1, -1)));
        return rec(a, b, c, 0, 0, 0, memo);
    }
};
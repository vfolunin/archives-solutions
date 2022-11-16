class Solution {
public:
    string shortestCommonSupersequence(string &a, string &b) {
        vector<vector<int>> scsLen(a.size() + 1, vector<int>(b.size() + 1));
        vector<vector<pair<pair<int, int>, char>>> from(a.size() + 1, vector<pair<pair<int, int>, char>>(b.size() + 1));
        
        for (int ai = 1; ai <= a.size(); ai++) {
            scsLen[ai][0] = ai;
            from[ai][0] = { { ai - 1, 0 }, a[ai - 1] };
        }
        
        for (int bi = 1; bi <= b.size(); bi++) {
            scsLen[0][bi] = bi;
            from[0][bi] = { { 0, bi - 1 }, b[bi - 1] };
        }
        
        for (int ai = 1; ai <= a.size(); ai++) {
            for (int bi = 1; bi <= b.size(); bi++) {
                if (a[ai - 1] == b[bi - 1]) {
                    scsLen[ai][bi] = scsLen[ai - 1][bi - 1] + 1;
                    from[ai][bi] = { { ai - 1, bi - 1 }, a[ai - 1] };
                } else if (scsLen[ai - 1][bi] + 1 < scsLen[ai][bi - 1] + 1) {
                    scsLen[ai][bi] = scsLen[ai - 1][bi] + 1;
                    from[ai][bi] = { { ai - 1, bi }, a[ai - 1] };
                } else {
                    scsLen[ai][bi] = scsLen[ai][bi - 1] + 1;
                    from[ai][bi] = { { ai, bi - 1 }, b[bi - 1] };
                }
            }
        }
        
        string scs;
        for (int ai = a.size(), bi = b.size(); ai || bi; ) {
            scs += from[ai][bi].second;
            auto [pai, pbi] = from[ai][bi].first;
            ai = pai;
            bi = pbi;
        }
        reverse(scs.begin(), scs.end());
        return scs;
    }
};
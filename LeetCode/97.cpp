class Solution {
public:
    bool isInterleave(string &a, string &b, string &c) {
        if (a.size() + b.size() != c.size())
            return 0;
        
        vector<vector<int>> can(a.size() + 1, vector<int>(b.size() + 1));
        
        can[0][0] = 1;
        for (int ai = 1; ai <= a.size(); ai++)
            can[ai][0] = can[ai - 1][0] && a[ai - 1] == c[ai - 1];
        for (int bi = 1; bi <= b.size(); bi++)
            can[0][bi] = can[0][bi - 1] && b[bi - 1] == c[bi - 1];
        
        for (int ai = 1; ai <= a.size(); ai++)
            for (int bi = 1; bi <= b.size(); bi++)
                can[ai][bi] = can[ai - 1][bi] && a[ai - 1] == c[ai + bi - 1] ||
                              can[ai][bi - 1] && b[bi - 1] == c[ai + bi - 1];
        
        return can[a.size()][b.size()];
    }
};
class Solution {
    int lcsLength(string &a, string &b) {
        vector<vector<int>> lcs(a.size() + 1, vector<int>(b.size() + 1));
        for (int ai = 1; ai <= a.size(); ai++) {
            for (int bi = 1; bi <= b.size(); bi++) {
                if (a[ai - 1] == b[bi - 1])
                    lcs[ai][bi] = lcs[ai - 1][bi - 1] + 1;
                else
                    lcs[ai][bi] = max(lcs[ai - 1][bi], lcs[ai][bi - 1]);
            }
        }
        return lcs[a.size()][b.size()];
    }
    
public:
    int minDistance(string a, string b) {
        return a.size() + b.size() - 2 * lcsLength(a, b);
    }
};
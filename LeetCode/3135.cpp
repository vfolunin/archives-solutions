class Solution {
public:
    int minOperations(string &a, string &b) {
        vector<vector<int>> lcs(a.size() + 1, vector<int>(b.size() + 1));
        int maxLcs = 0;
        for (int ai = 1; ai <= a.size(); ai++) {
            for (int bi = 1; bi <= b.size(); bi++) {
                if (a[ai - 1] == b[bi - 1]) {
                    lcs[ai][bi] = lcs[ai - 1][bi - 1] + 1;
                    maxLcs = max(maxLcs, lcs[ai][bi]);
                }
            }
        }
        return a.size() + b.size() - 2 * maxLcs;
    }
};
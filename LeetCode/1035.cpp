class Solution {
public:
    int maxUncrossedLines(vector<int> &a, vector<int> &b) {
        vector<vector<int>> res(a.size() + 1, vector<int>(b.size() + 1));
        
        unordered_map<int, int> seenA;
        
        for (int ai = 1; ai <= a.size(); ai++) {
            unordered_map<int, int> seenB;
            
            for (int bi = 1; bi <= b.size(); bi++) {
                res[ai][bi] = max(res[ai - 1][bi], res[ai][bi - 1]);
                if (a[ai - 1] == b[bi - 1])
                    res[ai][bi] = max(res[ai][bi], 1 + res[ai - 1][bi - 1]);

                if (seenA.count(b[bi - 1]))
                    res[ai][bi] = max(res[ai][bi], 1 + res[seenA[b[bi - 1]] - 1][bi - 1]);
                if (seenB.count(a[ai - 1]))
                    res[ai][bi] = max(res[ai][bi], 1 + res[ai - 1][seenB[a[ai - 1]] - 1]);

                seenB[b[bi - 1]] = bi;
            }
            
            seenA[a[ai - 1]] = ai;
        }
        
        return res[a.size()][b.size()];
    }
};
class Solution {
public:
    long long maxScore(vector<int> &a, vector<int> &b, int pairCount) {
        vector res(a.size(), vector(b.size(), vector<long long>(pairCount, -1e18)));
        for (int ai = 0; ai < a.size(); ai++) {
            for (int bi = 0; bi < b.size(); bi++) {
                for (int pi = 0; pi <= ai && pi <= bi && pi < pairCount; pi++) {
                    res[ai][bi][pi] = 1LL * a[ai] * b[bi] + (ai && bi && pi ? res[ai - 1][bi - 1][pi - 1] : 0);
                    if (ai)
                        res[ai][bi][pi] = max(res[ai][bi][pi], res[ai - 1][bi][pi]);
                    if (bi)
                        res[ai][bi][pi] = max(res[ai][bi][pi], res[ai][bi - 1][pi]);
                }
            }
        }
        return res.back().back().back();
    }
};
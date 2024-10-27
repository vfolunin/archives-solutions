class Solution {
public:
    int subsequencePairCount(vector<int> &a) {
        int maxValue = *max_element(a.begin(), a.end());

        vector<vector<int>> g(maxValue + 1, vector<int>(maxValue + 1));
        for (int a = 0; a < g.size(); a++)
            for (int b = 0; b < g.size(); b++)
                g[a][b] = gcd(a, b);

        const long long MOD = 1e9 + 7;
        vector ways(a.size() + 1, vector(maxValue + 1, vector<long long>(maxValue + 1)));
        ways[0][0][0] = 1;

        for (int i = 0; i < a.size(); i++) {
            for (int g1 = 0; g1 < ways[0].size(); g1++) {
                for (int g2 = 0; g2 < ways[0].size(); g2++) {
                    ways[i + 1][g1][g2] = (ways[i + 1][g1][g2] + ways[i][g1][g2]) % MOD;

                    int nextG1 = g[g1][a[i]];
                    ways[i + 1][nextG1][g2] = (ways[i + 1][nextG1][g2] + ways[i][g1][g2]) % MOD;

                    int nextG2 = g[g2][a[i]];
                    ways[i + 1][g1][nextG2] = (ways[i + 1][g1][nextG2] + ways[i][g1][g2]) % MOD;
                }
            }
        }

        long long res = 0;
        for (int g = 1; g < ways[0].size(); g++)
            res = (res + ways.back()[g][g]) % MOD;
        return res;
    }
};
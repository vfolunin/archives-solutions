class Solution {
public:
    int stringCount(int n) {
        const int MOD = 1e9 + 7;

        vector<vector<vector<vector<int>>>> ways(n + 1, vector<vector<vector<int>>>(3, vector<vector<int>>(2, vector<int>(2))));
        ways[0][0][0][0] = 1;

        for (int size = 0; size < n; size++) {
            for (int e = 0; e <= 2; e++) {
                for (int l = 0; l <= 1; l++) {
                    for (int t = 0; t <= 1; t++) {
                        ways[size + 1][e][l][t] = (ways[size + 1][e][l][t] + 23LL * ways[size][e][l][t]) % MOD;
                        ways[size + 1][min(e + 1, 2)][l][t] = (ways[size + 1][min(e + 1, 2)][l][t] + ways[size][e][l][t]) % MOD;
                        ways[size + 1][e][1][t] = (ways[size + 1][e][1][t] + ways[size][e][l][t]) % MOD;
                        ways[size + 1][e][l][1] = (ways[size + 1][e][l][1] + ways[size][e][l][t]) % MOD;
                    }
                }
            }
        }

        return ways[n][2][1][1];
    }
};
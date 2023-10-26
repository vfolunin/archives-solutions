class Solution {
public:
    int numberOfWays(int h, int w, int stepCount, vector<int> &start, vector<int> &finish) {
        const long long MOD = 1e9 + 7;
        vector<vector<long long>> ways(stepCount + 1, vector<long long>(4));

        if (start == finish)
            ways[0][0] = 1;
        else if (start[0] == finish[0])
            ways[0][1] = 1;
        else if (start[1] == finish[1])
            ways[0][2] = 1;
        else
            ways[0][3] = 1;

        for (int steps = 1; steps <= stepCount; steps++) {
            ways[steps][0] = (ways[steps - 1][1] + ways[steps - 1][2]) % MOD;
            ways[steps][1] = (ways[steps - 1][0] * (w - 1) + ways[steps - 1][1] * (w - 2) + ways[steps - 1][3]) % MOD;
            ways[steps][2] = (ways[steps - 1][0] * (h - 1) + ways[steps - 1][2] * (h - 2) + ways[steps - 1][3]) % MOD;
            ways[steps][3] = (ways[steps - 1][1] * (h - 1) + ways[steps - 1][2] * (w - 1) + ways[steps - 1][3] * (h - 2 + w - 2)) % MOD;
        }

        return ways[stepCount][0];
    }
};
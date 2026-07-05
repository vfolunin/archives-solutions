class Solution {
    void addDivisors(int value, unordered_set<int> &divisors) {
        for (int d = 2; d * d <= value; d++) {
            if (value % d == 0) {
                divisors.insert(d);
                divisors.insert(value / d);
            }
        }
        if (value != 1)
            divisors.insert(value);
    }

    int getScore(vector<int> &a, int d) {
        int curSum = 0, maxSum = -2e9;
        for (int value : a) {
            curSum = (value % d ? -1 : 1) * value + max(curSum, 0);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }

public:
    int divisibleGame(vector<int> &a) {
        unordered_set<int> divisors = { 2 };
        for (int value : a)
            addDivisors(value, divisors);
        
        int bestScore = -2e9, bestD;
        for (int d : divisors) {
            int score = getScore(a, d);
            if (bestScore < score || bestScore == score && bestD > d) {
                bestScore = score;
                bestD = d;
            }
        }

        const long long MOD = 1e9 + 7;
        return (1LL * bestScore * bestD % MOD + MOD) % MOD;
    }
};
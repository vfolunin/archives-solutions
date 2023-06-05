class Solution {
    const long long MOD = 1e9 + 7;

    long long rec(string &l, string &r, int i, int sum, int lMatch, int rMatch, vector<vector<vector<vector<int>>>> &memo) {
        int &res = memo[i][sum][lMatch][rMatch];
        if (res != -1)
            return res;

        if (i == l.size())
            return res = 1;
        
        int minDigit = lMatch ? l[i] - '0' : 0;
        int maxDigit = rMatch ? r[i] - '0' : 9;
        res = 0;

        for (int digit = minDigit; digit <= maxDigit && digit <= sum; digit++) {
            int nextSum = sum - digit;
            int nextLMatch = lMatch && digit == minDigit;
            int nextRMatch = rMatch && digit == maxDigit;
            res = (res + rec(l, r, i + 1, nextSum, nextLMatch, nextRMatch, memo)) % MOD;
        }
        
        return res;
    }

public:
    int count(string &l, string &r, int sumL, int sumR) {
        l = string(r.size() - l.size(), '0') + l;
        vector<vector<vector<vector<int>>>> memo(l.size() + 1, vector<vector<vector<int>>>(sumR + 1, vector<vector<int>>(2, vector<int>(2, -1))));
        return ((rec(l, r, 0, sumR, 1, 1, memo) - rec(l, r, 0, sumL - 1, 1, 1, memo)) % MOD + MOD) % MOD;
    }
};
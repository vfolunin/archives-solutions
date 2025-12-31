class Solution {
    int ones(int n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }

    int getSteps(int count) {
        if (count == 1)
            return 1;
        return 1 + getSteps(ones(count));
    }

    string toBin(long long n) {
        string res;
        for (; n; n /= 2)
            res += n % 2 + '0';
        reverse(res.begin(), res.end());
        return res;
    }

    long long rec(const string &s, int i, int ones, int targetOnes, bool isPrefixOfS, vector<vector<vector<long long>>> &memo) {
        long long &res = memo[i][ones][isPrefixOfS];
        if (res != -1)
            return res;

        if (ones > targetOnes)
            return res = 0;
        if (ones == targetOnes)
            return res = 1;
        if (i == s.size())
            return res = 0;

        res = 0;
        int maxDigit = isPrefixOfS ? s[i] - '0' : 1;

        for (int digit = 0; digit <= maxDigit; digit++) {
            int nextOnes = ones + digit;
            bool nextIsPrefixOfS = isPrefixOfS && digit == maxDigit;

            res += rec(s, i + 1, nextOnes, targetOnes, nextIsPrefixOfS, memo);
        }

        return res;
    }

public:
    long long popcountDepth(long long n, int targetSteps) {
        if (!targetSteps)
            return 1;

        string s = toBin(n);
        long long res = targetSteps > 1 ? 0 : -1;

        for (int targetOnes = 1; targetOnes < 60; targetOnes++) {
            if (getSteps(targetOnes) == targetSteps) {
                vector memo(s.size() + 1, vector(s.size() + 1, vector<long long>(2, -1)));
                res += rec(s, 0, 0, targetOnes, 1, memo);
            }
        }
        
        return res;
    }
};
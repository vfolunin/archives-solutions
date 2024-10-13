class Solution {
    const long long MOD = 1e9 + 7;

    long long rec(string &s, int game, int score, int last, vector<vector<vector<long long>>> &memo) {
        if (score > game + 1 || score < -game - 1)
            return 0;

        long long &res = memo[game][score + game + 1][last];
        if (res != -1)
            return res;

        static string letters = "EFW";
        int sLast = letters.find(s[game]);

        if (!game) {
            if (sLast == last)
                return res = score == 0;
            else if ((sLast + 1) % letters.size() == last)
                return res = score == 1;
            else
                return res = score == -1;
        }

        res = 0;
        for (int prev = 0; prev < letters.size(); prev++) {
            if (prev == last)
                continue;

            if (sLast == last)
                res = (res + rec(s, game - 1, score, prev, memo)) % MOD;
            else if ((sLast + 1) % letters.size() == last)
                res = (res + rec(s, game - 1, score - 1, prev, memo)) % MOD;
            else
                res = (res + rec(s, game - 1, score + 1, prev, memo)) % MOD;
        }
        return res;
    }

public:
    int countWinningSequences(string &s) {
        vector memo(s.size(), vector(s.size() * 2 + 1, vector<long long>(3, -1)));
        long long res = 0;
        for (int score = 1; score <= s.size(); score++)
            for (int last = 0; last < 3; last++)
                res = (res + rec(s, s.size() - 1, score, last, memo)) % MOD;
        return res;
    }
};
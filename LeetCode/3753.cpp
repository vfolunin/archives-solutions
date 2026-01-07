class Solution {
    pair<long long, long long> rec(const string &s, int i, int d1, int d2, bool hasLeadingZeros, bool isPrefixOfS,
                                   vector<vector<vector<vector<vector<pair<long long, long long>>>>>> &memo) {
        auto &[resSum, resCount] = memo[i][d1][d2][hasLeadingZeros][isPrefixOfS];
        if (resSum != -1)
            return { resSum, resCount };

        if (i == s.size()) {
            resSum = 0;
            resCount = 1;
            return { resSum, resCount };
        }

        resSum = resCount = 0;
        int maxDigit = isPrefixOfS ? s[i] - '0' : 9;

        for (int d3 = 0; d3 <= maxDigit; d3++) {
            bool nextHasLeadingZeros = hasLeadingZeros && !d2;
            bool nextIsPrefixOfS = isPrefixOfS && d3 == maxDigit;

            auto [sum, count] = rec(s, i + 1, d2, d3, nextHasLeadingZeros, nextIsPrefixOfS, memo);
            resSum += sum;
            resCount += count;

            if (!hasLeadingZeros && (d1 < d2 && d2 > d3 || d1 > d2 && d2 < d3))
                resSum += count;
        }

        return { resSum, resCount };
    }

public:
    long long totalWaviness(long long l, long long r) {
        vector memo(20, vector(10, vector(10, vector(2, vector<pair<long long, long long>>(2, { -1, -1 })))));
        long long rCount = rec(to_string(r), 0, 0, 0, 1, 1, memo).first;

        memo.assign(20, vector(10, vector(10, vector(2, vector<pair<long long, long long>>(2, { -1, -1 })))));
        long long lCount = rec(to_string(l - 1), 0, 0, 0, 1, 1, memo).first;

        return rCount - lCount;
    }
};
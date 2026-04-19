class Solution {
    long long rec(string &s, int i, vector<int> &pos, int posI, int last, bool isPrefixOfS,
                  vector<vector<vector<vector<long long>>>> &memo) {
        long long &res = memo[i][posI][last][isPrefixOfS];
        if (res != -1)
            return res;

        if (i == s.size())
            return 1;

        res = 0;
        int minDigit = i == pos[posI] ? last : 0;
        int maxDigit = isPrefixOfS ? s[i] - '0' : 9;

        for (int digit = minDigit; digit <= maxDigit; digit++) {
            int nextPosI = i == pos[posI] ? posI + 1 : posI;
            int nextLast = i == pos[posI] ? digit : last;
            bool nextIsPrefixOfS = isPrefixOfS && digit == maxDigit;

            res += rec(s, i + 1, pos, nextPosI, nextLast, nextIsPrefixOfS, memo);
        }

        return res;
    }

public:
    long long countGoodIntegersOnPath(long long l, long long r, string &path) {
        vector<int> pos = { 0 };
        for (char c : path)
            pos.push_back(pos.back() + (c == 'D' ? 4 : 1));
        
        string ls = to_string(l - 1);
        ls = string(16 - ls.size(), '0') + ls;
        vector memo(ls.size() + 1, vector(pos.size() + 1, vector(10, vector<long long>(2, -1))));
        long long lCount = rec(ls, 0, pos, 0, 0, 1, memo);

        string rs = to_string(r);
        rs = string(16 - rs.size(), '0') + rs;
        memo.assign(rs.size() + 1, vector(pos.size() + 1, vector(10, vector<long long>(2, -1))));
        long long rCount = rec(rs, 0, pos, 0, 0, 1, memo);

        return rCount - lCount;
    }
};
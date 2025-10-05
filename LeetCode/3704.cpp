class Solution {
    long long rec(const string &s, int i, int aSize, int bSize, int carry,
                  vector<vector<vector<vector<long long>>>> &memo,
                  vector<vector<vector<vector<int>>>> &memoIter, int iter) {
        long long &res = memo[i][aSize][bSize][carry];
        if (memoIter[i][aSize][bSize][carry] == iter)
            return res;
        memoIter[i][aSize][bSize][carry] = iter;

        if (i == s.size())
            return res = !carry;

        res = 0;
        int aMinDigit = 1, aMaxDigit = 9, bMinDigit = 1, bMaxDigit = 9;
        if (i >= aSize)
            aMinDigit = aMaxDigit = 0;
        if (i >= bSize)
            bMinDigit = bMaxDigit = 0;

        for (int aDigit = aMinDigit; aDigit <= aMaxDigit; aDigit++) {
            for (int bDigit = bMinDigit; bDigit <= bMaxDigit; bDigit++) {
                int sum = aDigit + bDigit + carry;
                if (sum % 10 == s[i] - '0')
                    res += rec(s, i + 1, aSize, bSize, sum / 10, memo, memoIter, iter);
            }
        }

        return res;
    }

public:
    long long countNoZeroPairs(long long n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());

        vector memo(s.size() + 1, vector(s.size() + 1, vector(s.size() + 1, vector<long long>(2))));
        vector memoIter(s.size() + 1, vector(s.size() + 1, vector(s.size() + 1, vector<int>(2))));
        long long res = 0;

        for (int aSize = 1, iter = 1; aSize <= s.size(); aSize++)
            for (int bSize = 1; bSize <= s.size(); bSize++, iter++)
                res += rec(s, 0, aSize, bSize, 0, memo, memoIter, iter);
                
        return res;
    }
};
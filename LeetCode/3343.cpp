class Solution {
    static const long long MOD = 1e9 + 7;

    long long c(int n, int k) {
        static vector<vector<long long>> memo(100, vector<long long>(100, -1));
        long long &res = memo[n][k];
        if (res != -1)
            return res;

        if (k == 0 || k == n)
            return res = 1;

        return res = (c(n - 1, k) + c(n - 1, k - 1)) % MOD;
    }

    int rec(vector<int> &count, int digit, int pos0, int pos1, int balance, vector<vector<vector<int>>> &memo) {
        int &res = memo[pos0][pos1][balance + 1000];
        if (res != -1)
            return res;

        if (digit == count.size())
            return res = !balance;
        
        int ways = 0;
        for (int count0 = 0, count1 = count[digit]; count0 <= count[digit]; count0++, count1--)
            if (count0 <= pos0 && count1 <= pos1)
                ways = (ways + c(pos0, count0) * c(pos1, count1) % MOD *
                        rec(count, digit + 1, pos0 - count0, pos1 - count1, balance + (count0 - count1) * digit, memo)) % MOD;
        return res = ways;
    }

public:
    int countBalancedPermutations(string &s) {
        vector<int> count(10);
        int sum = 0;
        for (char c : s) {
            count[c - '0']++;
            sum += c - '0';
        }
        
        if (sum % 2)
            return 0;
        
        vector memo(41, vector(41, vector<int>(2000, -1)));
        return rec(count, 0, (s.size() + 1) / 2, s.size() / 2, 0, memo);
    }
};
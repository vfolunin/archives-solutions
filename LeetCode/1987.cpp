class Solution {
public:
    int numberOfUniqueGoodSubsequences(string &s) {
        const long long MOD = 1e9 + 7;

        vector<long long> count(2);
        for (char c : s) {
            if (c == '0')
                count[0] = (count[0] + count[1]) % MOD;
            else
                count[1] = (count[1] + count[0] + 1) % MOD;
        }
        
        long long res = (count[0] + count[1]) % MOD;
        if (s.find('0') != -1)
            res = (res + 1) % MOD;

        return res;
    }
};
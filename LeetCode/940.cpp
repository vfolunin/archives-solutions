class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        vector<long long> res(s.size() + 1);
        res[0] = 1;

        vector<int> last(26, -1);

        for (int i = 1; i <= s.size(); i++) {
            res[i] = res[i - 1] * 2 % MOD;

            int &lastPos = last[s[i - 1] - 'a'];
            if (lastPos != -1)
                res[i] = ((res[i] - res[lastPos - 1]) % MOD + MOD) % MOD;
            lastPos = i;
        }

        return (res.back() + MOD - 1) % MOD;
    }
};
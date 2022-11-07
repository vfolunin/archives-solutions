class Solution {
    int getSum(vector<int> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }
    
public:
    int sumOfFlooredPairs(vector<int> a) {
        vector<int> p(1e5 + 1);
        for (int value : a)
            p[value]++;

        partial_sum(p.begin(), p.end(), p.begin());

        const long long MOD = 1e9 + 7;
        long long res = 0;

        for (int i = 1; i <= 1e5; i++) {
            if (!getSum(p, i, i))
                continue;
            for (int ratio = 1; i * ratio <= 1e5; ratio++) {
                int l = i * ratio, r = min<int>(i * (ratio + 1), p.size()) - 1;
                res = (res + 1LL * ratio * getSum(p, l, r) % MOD * getSum(p, i, i) % MOD) % MOD;
            }
        }

        return res;
    }
};
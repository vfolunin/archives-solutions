class Solution {
public:
    int getSum(vector<int> &a) {
        const long long MOD = 1e9 + 7;
        long long res = 0;
        
        long long size = 0, sum = 0;
        for (int i = 0; i < a.size(); i++) {
            if (i && a[i - 1] + 1 == a[i]) {
                size++;
                sum = (sum + 1LL * a[i] * size) % MOD;
            } else {
                size = 1;
                sum = a[i];
            }
            res = (res + sum) % MOD;
        }

        size = 0;
        sum = 0;
        for (int i = 0; i < a.size(); i++) {
            if (i && a[i - 1] - 1 == a[i]) {
                size++;
                sum = (sum + 1LL * a[i] * size) % MOD;
            } else {
                size = 1;
                sum = a[i];
            }
            res = (res + sum) % MOD;
        }

        for (int i = 0; i < a.size(); i++)
            res = (res - a[i] + MOD) % MOD;

        return res;
    }
};
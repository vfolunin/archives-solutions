class Solution {
public:
    int sumOfPower(vector<int> &a) {
        sort(a.begin(), a.end());

        const long long MOD = 1e9 + 7;
        long long res = 0, sum = 0;
        
        for (int i = a.size() - 1; i >= 0; i--) {
            long long cur = 1LL * a[i] * a[i] % MOD;
            
            res = (res + cur * a[i]) % MOD;
            res = (res + sum * a[i]) % MOD;
            
            sum = (sum * 2 + cur) % MOD;
        }
        
        return res;
    }
};
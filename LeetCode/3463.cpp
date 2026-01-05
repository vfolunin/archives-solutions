class Solution {
public:
    long long c(int n, int k) {
        if (n < k)
            return 0;

        int res = 1;
        for (int i = 1; i <= n; i++)
            res *= i;
        for (int i = 1; i <= k; i++)
            res /= i;
        for (int i = 1; i <= n - k; i++)
            res /= i;
        return res;
    }

    bool check(vector<int> &diff, int mod) {
        int res = 0;
        for (int i = 0; i < diff.size(); i++) {
            int factor = 1;
            for (int a = diff.size() - 1, b = i; a && b; a /= mod, b /= mod)
                factor = factor * c(a % mod, b % mod) % mod;
            res = (res + factor * diff[i]) % mod;
        }
        return !res;
    }

    bool hasSameDigits(string &s) {
        vector<int> diff(s.size() - 1);
        for (int i = 0; i < diff.size(); i++)
            diff[i] = (s[i] - s[i + 1] + 10) % 10;

        return check(diff, 2) && check(diff, 5);
    }
};
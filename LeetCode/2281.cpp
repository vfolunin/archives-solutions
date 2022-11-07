class Solution {
    const long long MOD = 1e9 + 7;

    long long getSum(vector<long long> &p, int l, int r) {
        if (r < 0 || l > r)
            return 0;
        return (p[r] - (l > 0 ? p[l - 1] : 0) + MOD) % MOD;
    }

public:
    int totalStrength(vector<int> &a) {
        vector<long long> p = { a.begin(), a.end() };
        for (int i = 0; i < 2; i++)
            for (int j = 1; j < p.size(); j++)
                p[j] = (p[j] + p[j - 1]) % MOD;

        vector<int> l(a.size(), -1), stack;
        for (int i = a.size() - 1; i >= 0; i--) {
            while (!stack.empty() && a[stack.back()] >= a[i]) {
                l[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }

        vector<int> r(a.size(), a.size());
        stack.clear();
        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && a[stack.back()] > a[i]) {
                r[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }

        long long res = 0;
        for (int i = 0; i < a.size(); i++) {
            long long left = getSum(p, l[i], i - 1) * (r[i] - i) % MOD;
            long long right = getSum(p, i, r[i] - 1) * (i - l[i]) % MOD;
            res = (res + (right - left + MOD) % MOD * a[i] % MOD) % MOD;
        }
        return res;
    }
};
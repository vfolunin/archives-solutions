class Solution {
    int primeDivisorCount(int n) {
        int res = 0;
        for (long long d = 2; d * d <= n; d++) {
            if (n % d == 0) {
                res++;
                while (n % d == 0)
                    n /= d;
            }
        }
        res += n != 1;
        return res;
    }

    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

public:
    int maximumScore(vector<int> &a, int opCount) {
        vector<int> score(a.size());
        for (int i = 0; i < a.size(); i++)
            score[i] = primeDivisorCount(a[i]);

        vector<int> r(a.size(), a.size()), stack;
        for (int i = 0; i < a.size(); i++) {
            while (!stack.empty() && score[stack.back()] < score[i]) {
                r[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }

        vector<int> l(a.size(), -1);
        stack.clear();
        for (int i = (int)a.size() - 1; i >= 0; i--) {
            while (!stack.empty() && score[stack.back()] <= score[i]) {
                l[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }

        vector<int> order(a.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int lhs, int rhs) {
            return a[lhs] > a[rhs];
        });

        const long long MOD = 1e9 + 7;
        long long res = 1;
        for (int i : order) {
            long long val = a[i];
            long long count = 1LL * (r[i] - i) * (i - l[i]);
            long long delta = min<long long>(count, opCount);
            opCount -= delta;
            res = res * binPow(val, delta, MOD) % MOD;
        }
        return res;
    }
};
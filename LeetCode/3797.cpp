class Solution {
    inline static const long long MOD = 1e9 + 7;

    long long getSum(vector<long long> &p, int l, int r) {
        return (p[r] - (l ? p[l - 1] : 0) + MOD) % MOD;
    }

public:
    int numberOfRoutes(vector<string> &a, int limit) {
        int h = a.size(), w = a[0].size();

        vector<long long> pWays(w);
        for (int x = 0; x < w; x++) {
            pWays[x] = a[h - 1][x] == '.';
            if (x)
                pWays[x] = (pWays[x] + pWays[x - 1]) % MOD;
        }

        vector<long long> pSideWays(w);
        for (int x = 0; x < w; x++) {
            if (a[h - 1][x] == '.') {
                int l = max(x - limit, 0);
                int r = min(x + limit, w - 1);
                pSideWays[x] = (getSum(pWays, l, r) - getSum(pWays, x, x) + MOD) % MOD;
            }
            if (x)
                pSideWays[x] = (pSideWays[x] + pSideWays[x - 1]) % MOD;
        }

        for (int x = 0; x < w; x++)
            pWays[x] = (pWays[x] + pSideWays[x]) % MOD;

        for (int y = h - 2; y >= 0; y--) {
            vector<long long> pNextWays(w);
            for (int x = 0; x < w; x++) {
                if (a[y][x] == '.') {
                    int delta = sqrt(limit * limit - 1);
                    int l = max(x - delta, 0);
                    int r = min(x + delta, w - 1);
                    pNextWays[x] = getSum(pWays, l, r);
                }
                if (x)
                    pNextWays[x] = (pNextWays[x] + pNextWays[x - 1]) % MOD;
            }

            pWays.swap(pNextWays);

            vector<long long> pSideWays(w);
            for (int x = 0; x < w; x++) {
                if (a[y][x] == '.') {
                    int l = max(x - limit, 0);
                    int r = min(x + limit, w - 1);
                    pSideWays[x] = (getSum(pWays, l, r) - getSum(pWays, x, x) + MOD) % MOD;
                }
                if (x)
                    pSideWays[x] = (pSideWays[x] + pSideWays[x - 1]) % MOD;
            }

            for (int x = 0; x < w; x++)
                pWays[x] = (pWays[x] + pSideWays[x]) % MOD;
        }

        return pWays.back();
    }
};
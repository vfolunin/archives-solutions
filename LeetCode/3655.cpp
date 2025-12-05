class Solution {
    long long binPow(long long x, long long p, long long mod) {
        if (!p)
            return 1 % mod;
        if (p % 2)
            return binPow(x, p - 1, mod) * x % mod;
        long long r = binPow(x, p / 2, mod);
        return r * r % mod;
    }

    long long inv(long long x, long long mod) {
        return binPow(x, mod - 2, mod);
    }

public:
    int xorAfterQueries(vector<int> &a, vector<vector<int>> &queries) {
        const long long MOD = 1e9 + 7;
        int threshold = sqrt(a.size());
        map<pair<int, int>, vector<long long>> deltaMap;

        for (vector<int> &query : queries) {
            int l = query[0], r = query[1], step = query[2];
            long long delta = query[3];

            if (step < threshold) {
                r = l + (r - l) / step * step;
                int dl = l / step, dr = r / step + 1;

                vector<long long> &deltas = deltaMap[{ l % step, step }];
                if (deltas.size() <= dr)
                    deltas.resize(dr + 1, 1);
                
                deltas[dl] = (deltas[dl] * delta) % MOD;
                deltas[dr] = (deltas[dr] * inv(delta, MOD)) % MOD;
            } else {
                for (int i = l; i <= r; i += step)
                    a[i] = (a[i] * delta) % MOD;
            }
        }

        for (auto &[key, deltas] : deltaMap) {
            auto &[offset, step] = key;
            long long delta = 1;
            for (int i = offset, di = 0; i < a.size() && di < deltas.size(); i += step, di++) {
                delta = (delta * deltas[di]) % MOD;
                a[i] = (a[i] * delta) % MOD;
            }
        }

        int xorSum = 0;
        for (int value : a)
            xorSum ^= value;
        return xorSum;
    }
};
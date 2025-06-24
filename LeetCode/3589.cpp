class SparseTable {
    vector<int> lg;
    vector<vector<pair<int, int>>> st;

public:
    SparseTable(vector<int> &a) {
        lg.resize(a.size() + 1);
        for (int i = 2; i <= a.size(); i++)
            lg[i] = lg[i / 2] + 1;

        st.emplace_back();
        for (int i = 0; i < a.size(); i++)
            st[0].push_back({ a[i], a[i] });
        for (int level = 1, levelWidth = 2; levelWidth <= a.size(); level++, levelWidth *= 2) {
            st.emplace_back();
            for (int i = 0; i + levelWidth <= a.size(); i++)
                st[level].push_back({
                    min(st[level - 1][i].first, st[level - 1][i + levelWidth / 2].first),
                    max(st[level - 1][i].second, st[level - 1][i + levelWidth / 2].second)
                });
        }
    }

    int getDiff(int l, int r) {
        int level = lg[r - l + 1], levelWidth = 1 << level;
        int minValue = min(st[level][l].first, st[level][r - levelWidth + 1].first);
        int maxValue = max(st[level][l].second, st[level][r - levelWidth + 1].second);
        return maxValue - minValue;
    }
};

class Solution {
    vector<int> getPrimes(int n) {
        vector<int> isPrime(n + 1, 1), primes;

        for (int i = 2; i < isPrime.size(); i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (long long j = 1LL * i * i; j < isPrime.size(); j += i)
                    isPrime[j] = 0;
            }
        }

        return primes;
    }

public:
    int primeSubarray(vector<int> &a, int limit) {
        static vector<int> primes = getPrimes(5e4);
        vector<int> aPrimes, primePos = { -1 };
        for (int i = 0; i < a.size(); i++) {
            if (binary_search(primes.begin(), primes.end(), a[i])) {
                aPrimes.push_back(a[i]);
                primePos.push_back(i);
            }
        }
        primePos.push_back(a.size());
        
        SparseTable sparseTable(aPrimes);
        int res = 0;

        for (int i = 0; i < aPrimes.size(); i++) {
            int l = i, r = aPrimes.size();
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (sparseTable.getDiff(i, m) <= limit)
                    l = m;
                else
                    r = m;
            }

            int lCount = primePos[i + 1] - primePos[i];
            int rCount = primePos[r + 1] - primePos[i + 2];
            res += lCount * rCount;
        }

        return res;
    }
};
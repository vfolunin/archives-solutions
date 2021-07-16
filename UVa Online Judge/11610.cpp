#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<vector<int>, vector<int>> getPrimes() {
    const int N = 1e7;
    vector<int> factorCount(N), primes;
    for (int i = 2; i < N; i++) {
        if (!factorCount[i]) {
            primes.push_back(i);
            for (long long power = i; power < N; power *= i)
                for (int j = power; j < N; j += power)
                    factorCount[j]++;
        }
    }
    return { primes, factorCount };
}

struct BIT {
    vector<int> f;

    int sum(int r) {
        int res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += f[r];
        return res;
    }

    void add(int i, int v) {
        for (; i < f.size(); i |= i + 1)
            f[i] += v;
    }

    BIT(int size) {
        f.resize(size);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    auto [primes, factorCount] = getPrimes();
    while (primes.back() > 1e6)
        primes.pop_back();

    vector<int> reversePrimes(primes.size());
    for (int i = 0; i < primes.size(); i++) {
        int rp = 0, p = primes[primes.size() - 1 - i];

        while (p) {
            rp = rp * 10 + p % 10;
            p /= 10;
        }
        while (rp < 1e6)
            rp *= 10;

        reversePrimes[i] = rp;
    }

    sort(reversePrimes.begin(), reversePrimes.end());

    BIT factor(primes.size()), active(primes.size());
    for (int i = 0; i < reversePrimes.size(); i++) {
        factor.add(i, factorCount[reversePrimes[i]]);
        active.add(i, 1);
    }

    char type;
    int arg;
    while (cin >> type >> arg) {
        if (type == 'q') {
            int l = -1, r = reversePrimes.size();
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (active.sum(m) < arg + 1)
                    l = m;
                else
                    r = m;
            }
            cout << factor.sum(r) << "\n";
        } else {
            int i = lower_bound(reversePrimes.begin(), reversePrimes.end(), arg) - reversePrimes.begin();
            factor.add(i, -factorCount[arg]);
            active.add(i, -1);
        }
    }
}
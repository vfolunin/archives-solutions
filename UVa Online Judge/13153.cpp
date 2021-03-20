#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct DSU {
    vector<int> id;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
    }
};

pair<vector<int>, vector<int>> getPrimes() {
    const int N = 1e6 + 1;
    vector<int> minDivisor(N, 1), primes;
    for (int i = 2; i < N; i++) {
        if (minDivisor[i] == 1) {
            primes.push_back(i);
            minDivisor[i] = i;
            for (long long j = 1LL * i * i; j < N; j += i)
                minDivisor[j] = i;
        }
    }
    return { minDivisor, primes };
}

void solve(int test) {
    int n;
    cin >> n;
    
    static auto [minDivisor, primes] = getPrimes();

    DSU dsu(primes.size() + n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        while (x != 1) {
            int d = minDivisor[x];
            int p = lower_bound(primes.begin(), primes.end(), d) - primes.begin();
            dsu.merge(p, primes.size() + i);
            while (x % d == 0)
                x /= d;
        }
    }

    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(dsu.find(primes.size() + i));

    cout << "Case " << test << ": " << s.size() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

set<int> getPrimes() {
    const int N = 32000;
    vector<int> isPrime(N, 1);
    set<int> primes;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.insert(i);
            for (long long j = 1LL * i * i; j < N; j += i)
                isPrime[j] = 0;
        }
    }
    return primes;
}

void solve() {
    int n;
    cin >> n;

    static set<int> primes = getPrimes();
    vector<int> res;
    for (int p : primes) {
        if (p > n - p)
            break;
        if (primes.count(n - p))
            res.push_back(p);
    }

    cout << n << " has " << res.size() << " representation(s)\n";
    for (int x : res)
        cout << x << "+" << n - x << "\n";
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
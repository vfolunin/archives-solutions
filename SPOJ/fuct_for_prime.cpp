#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

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

void solve() {
    int l, r;
    cin >> l >> r;

    if (l > r)
        swap(l, r);

    static vector<int> primes = getPrimes(500);
    for (int i = lower_bound(primes.begin(), primes.end(), l) - primes.begin(); i < primes.size() && primes[i] <= r; i++)
        cout << primes[i] << (i + 1 < primes.size() && primes[i + 1] <= r ? "," : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
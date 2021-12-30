#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 1e6;
    vector<int> isPrime(N, 1), primes;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j < N; j += i)
                isPrime[j] = 0;
        }
    }
    return primes;
}

vector<int> getTwinPrimes() {
    vector<int> primes = getPrimes(), twinPrimes;
    for (int i = 1; i < primes.size(); i++) {
        if (primes[i - 1] + 2 == primes[i]) {
            if (twinPrimes.empty() || twinPrimes.back() != primes[i - 1])
                twinPrimes.push_back(primes[i - 1]);
            twinPrimes.push_back(primes[i]);
        }
    }
    return twinPrimes;
}

void solve() {
    int l, r;
    cin >> l >> r;
    if (l > r)
        swap(l, r);

    static vector<int> twinPrimes = getTwinPrimes();

    cout << upper_bound(twinPrimes.begin(), twinPrimes.end(), r) -
            lower_bound(twinPrimes.begin(), twinPrimes.end(), l) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
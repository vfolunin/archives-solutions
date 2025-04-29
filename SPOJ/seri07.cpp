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

vector<long long> prepare() {
    vector<int> primes = getPrimes(1e6);
    vector<long long> res;

    for (int i = 0; i < 1e4; i++)
        res.push_back(1LL * primes[i * 3] * primes[i * 3 + 1] + primes[i * 3 + 2]);

    return res;
}

void solve() {
    int n;
    cin >> n;

    static vector<long long> res = prepare();

    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
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
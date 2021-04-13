#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 65536;
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

int phi(int n) {
    static vector<int> primes = getPrimes();
    int res = n;
    for (int i = 0; 1LL * primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            while (n % primes[i] == 0)
                n /= primes[i];
            res -= res / primes[i];
        }
    }
    if (n > 1)
        res -= res / n;
    return res;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    cout << phi(n) / 2 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
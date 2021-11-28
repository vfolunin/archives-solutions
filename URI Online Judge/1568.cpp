#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 5e6;
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

bool solve() {
    long long n;
    if (!(cin >> n))
        return 0;

    if (!n) {
        cout << "0\n";
        return 1;
    }

    while (n % 2 == 0)
        n /= 2;

    static vector<int> primes = getPrimes();

    int res = 1;
    for (int i = 1; i < primes.size() && 1LL * primes[i] * primes[i] <= n; i++) {
        if (n % primes[i])
            continue;

        int power = 0;
        while (n % primes[i] == 0) {
            n /= primes[i];
            power++;
        }
        res *= power + 1;
    }
    if (n > 1)
        res *= 2;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
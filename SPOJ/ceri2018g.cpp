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

long long getPhi(long long n) {
    static vector<int> primes = getPrimes(1e4);
    for (int p : primes)
        if (n % p == 0)
            return (p - 1) * (n / p - 1);
    return 0;
}

static long long gcdex(long long a, long long b, long long &x, long long &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1, d = gcdex(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return d;
}

long long getD(long long e, long long phi) {
    long long x, y;
    gcdex(e, phi, x, y);
    return (x % phi + phi) % phi;
}

long long binPow(long long x, long long p, long long mod) {
    if (!p)
        return 1 % mod;
    if (p % 2)
        return binPow(x, p - 1, mod) * x % mod;
    long long r = binPow(x, p / 2, mod);
    return r * r % mod;
}

void solve() {
    long long n, e, c;
    cin >> n >> e >> c;

    long long phi = getPhi(n);
    long long d = getD(e, phi);

    cout << binPow(c, d, n) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
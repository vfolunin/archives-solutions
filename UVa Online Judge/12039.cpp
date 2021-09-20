#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 2e7;
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

long long goldbach(int n) {
    n = n / 2 * 2;

    static vector<int> primes = getPrimes();

    long long res = 0;
    int l = 1, r = upper_bound(primes.begin(), primes.end(), n) - primes.begin();

    for (; primes[l] < n; l++) {
        while (r > 0 && primes[l] + primes[r] > n)
            r--;
        res += r;
        res -= l <= r;
    }

    return res / 2;
}

long long goldbach(int l, int r) {
    return goldbach(r) - (l ? goldbach(l - 1) : 0);
}

bool solve() {
    int l, r;
    cin >> l >> r;

    if (!l && !r)
        return 0;

    cout << goldbach(l, r) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
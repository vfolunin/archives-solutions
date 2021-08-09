#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 1e7;
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

int primeDivisorCount(long long n) {
    static vector<int> primes = getPrimes();
    int res = 0;
    for (int i = 0; 1LL * primes[i] * primes[i] <= n; i++) {
        while (n % primes[i] == 0) {
            res++;
            n /= primes[i];
        }
    }
    res += n > 1;
    return res;
}

bool solve() {
    long long n;
    cin >> n;

    if (n == 1)
        return 0;

    cout << primeDivisorCount(n) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
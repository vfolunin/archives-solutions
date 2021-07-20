#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getPrimes() {
    const long long N = 2e7 + 5;
    vector<int> isPrime(N, 1);
    vector<long long> primes;
    for (long long i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (long long j = i * i; j < N; j += i)
                isPrime[j] = 0;
        }
    }
    return primes;
}

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    static vector<long long> primes = getPrimes();

    long long x = 4 * n - 3, divisorCount = 1;
    for (int i = 0; primes[i] * primes[i] <= x; i++) {
        long long power = 0;
        while (x % primes[i] == 0) {
            x /= primes[i];
            power++;
        }
        divisorCount *= power + 1;
    }
    if (x > 1)
        divisorCount *= 2;

    cout << n << " " << divisorCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
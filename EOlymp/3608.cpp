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

bool isPrime(long long n) {
    if (n < 2)
        return 0;

    static vector<int> primes = getPrimes(1e5);
    for (int i = 0; 1LL * primes[i] * primes[i] <= n; i++)
        if (n % primes[i] == 0)
            return 0;

    return 1;
}

void solve() {
    long long n;
    cin >> n;

    do {
        n++;
    } while (!isPrime(n));

    cout << n << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
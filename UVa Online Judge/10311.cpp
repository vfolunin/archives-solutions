#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getPrimes() {
    const int N = 4e4;
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

bool isPrime(int n) {
    if (n < 2)
        return 0;

    static vector<int> primes = getPrimes();

    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++)
        if (n % primes[i] == 0)
            return 0;
    return 1;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    if (n % 2) {
        if (n > 1 && isPrime(n - 2))
            cout << n << " is the sum of 2 and " << n - 2 << ".\n";
        else
            cout << n << " is not the sum of two primes!\n";
    } else {
        for (int i = (n - 1) / 2; i; i--) {
            if (isPrime(i) && isPrime(n - i)) {
                cout << n << " is the sum of " << i << " and " << n - i << ".\n";
                return 1;
            }
        }
        cout << n << " is not the sum of two primes!\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
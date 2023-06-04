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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    vector<int> primes = getPrimes(1.1e5);

    bool found = 0;
    for (int i = 1; i + 1 < primes.size(); i++) {
        if (l <= primes[i] && primes[i] <= r && primes[i - 1] + primes[i + 1] == 2 * primes[i]) {
            cout << primes[i] << " ";
            found = 1;
        }
    }

    if (!found)
        cout << 0;
}
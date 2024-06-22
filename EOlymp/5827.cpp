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

bool solve() {
    int value;
    cin >> value;

    if (!value)
        return 0;

    static vector<int> primes = getPrimes(1.3e6);
    int i = lower_bound(primes.begin(), primes.end(), value) - primes.begin();

    if (primes[i] == value)
        cout << "0\n";
    else
        cout << primes[i] - primes[i - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
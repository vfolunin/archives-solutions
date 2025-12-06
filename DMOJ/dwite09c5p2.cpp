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
    if (!(cin >> value))
        return 0;

    static vector<int> primes = getPrimes(200);

    int i = lower_bound(primes.begin(), primes.end(), value) - primes.begin();
    int li = i - 2;
    int ri = i + (primes[i] == value) + 1;

    cout << primes[0 <= li && value - primes[li] < primes[ri] - value ? li : ri] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
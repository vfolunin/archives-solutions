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
    int sum;
    if (!(cin >> sum))
        return 0;

    static vector<int> primes = getPrimes(2e4);

    for (int a = sum / 2, b = sum / 2; 1; a--, b++) {
        if (binary_search(primes.begin(), primes.end(), a) &&
            binary_search(primes.begin(), primes.end(), b)) {
            cout << a << " " << b << "\n";
            return 1;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
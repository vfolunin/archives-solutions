#include <iostream>
#include <algorithm>
#include <cmath>
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

pair<vector<int>, vector<int>> prepare() {
    vector<int> primes = getPrimes(1e6);
    vector<int> fermatPrimes;
    for (int prime : primes) {
        for (int a = 1; a * a * 2 <= prime; a++) {
            int b = sqrt(prime - a * a);
            if (a * a + b * b == prime) {
                fermatPrimes.push_back(prime);
                break;
            }
        }
    }
    return { primes, fermatPrimes };
}

bool solve() {
    int l, r;
    cin >> l >> r;

    if (l == -1 && r == -1)
        return 0;

    static auto [primes, fermatPrimes] = prepare();

    cout << l << " " << r << " ";
    cout << upper_bound(primes.begin(), primes.end(), r) - lower_bound(primes.begin(), primes.end(), l) << " ";
    cout << upper_bound(fermatPrimes.begin(), fermatPrimes.end(), r) - lower_bound(fermatPrimes.begin(), fermatPrimes.end(), l) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
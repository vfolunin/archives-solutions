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

    vector<int> primes = getPrimes(r);

    set<int> sums;
    for (int i = 0; i < primes.size(); i++)
        for (int j = i; j < primes.size() && primes[i] + primes[j] <= r; j++)
            sums.insert(primes[i] + primes[j]);

    for (int sum : sums)
        if (l <= sum)
            cout << sum << "\n";
}
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

    int queryCount;
    cin >> queryCount;

    vector<int> primes = getPrimes(1e6);

    for (int i = 0; i < queryCount; i++) {
        long long l, r;
        cin >> l >> r;

        int res = 0;
        for (int prime : primes)
            for (long long p = 1LL * prime * prime; p <= r; p *= prime)
                res += l <= p && p <= r;
        
        cout << res << "\n";
    }
}
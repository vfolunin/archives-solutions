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

long long rec(int divisorCount, int primeIndex) {
    if (divisorCount == 1)
        return 1;

    static vector<int> primes = getPrimes(1000);
    long long res = 1e15;

    for (int d = 2; d <= divisorCount; d++) {
        if (divisorCount % d)
            continue;

        long long cur = rec(divisorCount / d, primeIndex + 1);
        for (int j = 0; j < d - 1 && cur < res; j++)
            cur *= primes[primeIndex];

        res = min(res, cur);
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int divisorCount;
    cin >> divisorCount;

    cout << min(rec(divisorCount * 2, 0), rec(divisorCount * 2 - 1, 0));
}
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

    int targetSize;
    cin >> targetSize;

    vector<int> primes = getPrimes(1000);
    primes.erase(primes.begin(), upper_bound(primes.begin(), primes.end(), 100));

    const long long MOD = 1e9 + 9;
    vector<vector<long long>> ways(targetSize + 1, vector<long long>(100));

    for (int prime : primes)
        ways[3][prime % 100]++;

    for (int size = 4; size <= targetSize; size++)
        for (int prime : primes)
            ways[size][prime % 100] = (ways[size][prime % 100] + ways[size - 1][prime / 10]) % MOD;

    long long res = 0;
    for (long long value : ways.back())
        res = (res + value) % MOD;

    cout << res;
}
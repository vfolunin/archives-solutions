#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPrime(long long n) {
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

vector<long long> prepareBasePrimes() {
    vector<long long> primes;
    for (long long i = 2; i * i < 3e9; i++)
        if (isPrime(i))
            primes.push_back(i);
    return primes;
}

vector<long long> getPrimes(long long l, long long r) {
    static vector<long long> basePrimes = prepareBasePrimes();

    if (l == 1)
        l++;

    vector<int> isPrime(r - l + 1, 1);
    for (long long p : basePrimes) {
        long long from = (l + p - 1) / p * p;
        if (from == p)
            from += p;
        for (long long i = from; i <= r; i += p)
            isPrime[i - l] = 0;
    }
    
    vector<long long> primes;
    for (long long i = l; i <= r; i++)
        if (isPrime[i - l])
            primes.push_back(i);

    return primes;
}

bool solve() {
    long long l, r;
    if (!(cin >> l >> r))
        return 0;

    vector<long long> primes = getPrimes(l, r);

    if (primes.size() < 2) {
        cout << "There are no adjacent primes.\n";
        return 1;
    }

    int res1 = 0, res2 = 0;
    for (int i = 1; i + 1 < primes.size(); i++) {
        if (primes[i + 1] - primes[i] < primes[res1 + 1] - primes[res1])
            res1 = i;
        if (primes[i + 1] - primes[i] > primes[res2 + 1] - primes[res2])
            res2 = i;
    }

    cout << primes[res1] << "," << primes[res1 + 1] << " are closest, ";
    cout << primes[res2] << "," << primes[res2 + 1] << " are most distant.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
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

    int n;
    cin >> n;

    vector<int> primes = getPrimes(n);
    vector<int> count(primes.size());

    int res = 0;
    for (int i = primes.size() - 1; i >= 0; i--) {
        while (n % primes[i] == 0) {
            n /= primes[i];
            count[i]++;
        }
        res += count[i];
        if (i)
            count[i - 1] += count[i];
    }

    cout << res;
}
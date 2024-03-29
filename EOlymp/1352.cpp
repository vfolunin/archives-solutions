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

    int mod;
    cin >> mod;

    vector<int> primes = getPrimes(1e5);
    int remainder = 0;

    for (int i = 0; i < primes.size(); i++) {
        remainder = (remainder + primes[i]) % mod;
        if (!remainder) {
            cout << i + 1;
            break;
        }
    }
}
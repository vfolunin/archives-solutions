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

int reverse(int n) {
    int res = 0;
    for (; n; n /= 10)
        res = res * 10 + n % 10;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> primes = getPrimes(1e6);
    vector<int> luckyPrimes;

    for (int prime : primes)
        if (prime != reverse(prime) && binary_search(primes.begin(), primes.end(), reverse(prime)))
            luckyPrimes.push_back(prime);

    int index;
    cin >> index;
    index--;

    cout << (index < luckyPrimes.size() ? luckyPrimes[index] : -1);
}
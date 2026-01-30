#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getPrimeCount(int n) {
    vector<bool> isPrime(sqrt(n) + 1, 1);
    vector<int> primes;
    for (int i = 2; i < isPrime.size(); i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < isPrime.size(); j += i)
                isPrime[j] = 0;
        }
    }

    int primeCount = 0;
    vector<bool> isPrimeBlock(1e4);
    for (int factor = 0, start = 0; factor * isPrimeBlock.size() <= n; factor++, start += isPrimeBlock.size()) {
        fill(isPrimeBlock.begin(), isPrimeBlock.end(), 1);
        if (factor == 0)
            isPrimeBlock[0] = isPrimeBlock[1] = 0;

        for (int i : primes)
            for (int j = max((start + i - 1) / i, i) * i - start; j < isPrimeBlock.size(); j += i)
                isPrimeBlock[j] = 0;

        for (int i = 0; i < isPrimeBlock.size() && start + i <= n; i++)
            primeCount += isPrimeBlock[i];
    }
    return primeCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << getPrimeCount(n);
}
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

void rec(int divisorCount, int primeIndex, long long value, long long &minValue) {
    if (divisorCount == 1) {
        minValue = value;
        return;
    }

    static vector<int> primes = getPrimes(40);

    for (int curDivisorCount = divisorCount; curDivisorCount >= 2; curDivisorCount--)
        if (divisorCount % curDivisorCount == 0 && value * pow(primes[primeIndex], curDivisorCount - 1) < minValue)
            rec(divisorCount / curDivisorCount, primeIndex + 1, value * pow(primes[primeIndex], curDivisorCount - 1), minValue);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int divisorCount;
    cin >> divisorCount;

    long long res = 1e15 + 2;
    rec(divisorCount, 0, 1, res);

    cout << (res <= 1e15 + 1 ? res : 0);
}
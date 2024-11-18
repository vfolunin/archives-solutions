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

unsigned long long rec(vector<int> &primes, int index, int powerLimit, unsigned long long productLimit, unsigned long long product, unsigned long long divisorCount) {
    unsigned long long res = divisorCount;
    if (index == primes.size())
        return res;

    unsigned long long power = 1;
    for (int i = 1; i <= powerLimit; i++) {
        power *= primes[index];
        unsigned long long nextProduct = product * power;
        if (nextProduct <= productLimit && power && nextProduct / power == product)
            res = max(res, rec(primes, index + 1, i, productLimit, nextProduct, divisorCount * (i + 1)));
        else
            break;
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unsigned long long productLimit;
    cin >> productLimit;

    vector<int> primes = getPrimes(60);

    cout << rec(primes, 0, 64, productLimit, 1, 1);
}
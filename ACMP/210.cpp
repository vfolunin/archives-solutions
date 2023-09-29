#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<int, int> factorize(int n) {
    map<int, int> factorization;

    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization[d]++;
            n /= d;
        }
    }
    if (n != 1)
        factorization[n]++;

    return factorization;
}

int primeCount(int n, int p) {
    int res = 0;
    while (n % p == 0) {
        n /= p;
        res++;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    map<int, int> factorization = factorize(n);

    int primeProduct = 1;
    for (auto &[prime, power] : factorization)
        primeProduct *= prime;

    int additionalFactor = 1;
    for (auto &[prime, power] : factorization)
        while ((1 + primeCount(additionalFactor, prime)) * primeProduct * additionalFactor < power)
            additionalFactor++;

    cout << primeProduct * additionalFactor;
}
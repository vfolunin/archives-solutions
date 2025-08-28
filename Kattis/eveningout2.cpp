#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<long long, int> factorize(long long n) {
    map<long long, int> factorization;
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

void rec(map<long long, int> &factorization, map<long long, int>::iterator it,
         long long p, long long b, long long &res) {
    if (it == factorization.end()) {
        res = min(res, abs(p - b));
        return;
    }

    long long d = 1;
    rec(factorization, next(it), p * d, b, res);
    for (int i = 0; i < it->second; i++) {
        d *= it->first;
        rec(factorization, next(it), p * d, b, res);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, b;
    cin >> a >> b;

    map<long long, int> factorization = factorize(a);
    long long res = 1e18;
    rec(factorization, factorization.begin(), 1, b, res);

    cout << res;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n;
    cin >> n;

    long long res = 0;
    for (auto &[_, count] : factorize(abs(n)))
        res = gcd(res, count);

    if (n < 0)
        while (res % 2 == 0)
            res /= 2;

    cout << res;
}
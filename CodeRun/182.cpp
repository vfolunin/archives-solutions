#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

map<long long, int> factorize(long long n) {
    map<long long, int> factors;

    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factors[d]++;
            n /= d;
        }
    }
    if (n != 1)
        factors[n]++;

    return factors;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, b;
    cin >> a >> b;

    map<long long, int> fa = factorize(a), fb = factorize(b);
    for (auto &[f, count] : fa) {
        if (fb[f] < count) {
            cout << 0;
            return 0;
        }
    }

    long long res = 1;
    for (auto &[f, count] : fb)
        if (count != fa[f])
            res *= 2;

    cout << res;
}
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

long long binPow(long long x, long long p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1) * x;
    long long r = binPow(x, p / 2);
    return r * r;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int res = 1;
    for (auto &[d, p] : factorize(n))
        res *= binPow(d, p / 2 * 2);

    cout << res;
}
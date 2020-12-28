#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

long long binPow(long long x, long long p, long long m) {
    if (p == 0)
        return 1 % m;
    if (p % 2)
        return binPow(x, p - 1, m) * x % m;
    long long r = binPow(x, p / 2, m);
    return r * r % m;
}

bool solve() {
    long long x, p, m;
    if (!(cin >> x >> p >> m))
        return 0;

    cout << binPow(x, p, m) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
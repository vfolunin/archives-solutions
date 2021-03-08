#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long pow(long long x, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return pow(x, p - 1) * x;
    long long r = pow(x, p / 2);
    return r * r;
}

bool isPow(long long n, int p) {
    if (n < 0) {
        if (p % 2 == 0)
            return 0;
        n = -n;
    }
    long long r = pow(n, 1.0 / p);
    for (int i = -2; i <= 2; i++)
        if (pow(r + i, p) == n)
            return 1;
    return 0;
}

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    int p = 32;
    while (!isPow(n, p))
        p--;

    cout << p << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
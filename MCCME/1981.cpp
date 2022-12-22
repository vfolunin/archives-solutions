#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(long long p, long long n, long long k, long long x) {
    long long cost = x + x * p / 100;
    return cost * k <= n;
}

long long getPrice(long long p, long long n, long long k, long long l, long long r) {
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(p, n, k, m))
            l = m;
        else
            r = m;
    }
    return l;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long l, r, p, n, k;
    cin >> l >> r >> p >> n >> k;
    l *= 100;
    r *= 100;
    n *= 100;

    if (can(0, n, k, r + 1))
        cout << getPrice(0, n, k, r + 1, 1e12) / 100;
    else if (can(p, n, k, l))
        cout << getPrice(p, n, k, l, r) / 100;
    else
        cout << getPrice(0, n, k, -1, l - 1) / 100;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(long long k2, long long k3, long long k4, long long k5) {
    long long num = k2 * 2 + k3 * 3 + k4 * 4 + k5 * 5;
    long long den = k2 + k3 + k4 + k5;
    return num * 10 >= den * 35;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long k2, k3, k4;
    cin >> k2 >> k3 >> k4;

    long long l = -1, r = 1;
    while (!can(k2, k3, k4, r))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(k2, k3, k4, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}
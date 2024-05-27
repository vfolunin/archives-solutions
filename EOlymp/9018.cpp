#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

bool can(long long a, long long b, long long n, long long m) {
    return m / a + m / b - m / lcm(a, b) < n;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, b, n;
    cin >> a >> b >> n;

    long long l = 0, r = 1;
    while (can(a, b, n, r))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(a, b, n, m))
            l = m;
        else
            r = m;
    }

    cout << r;
}
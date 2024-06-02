#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

bool can(long long a, long long b, long long c, long long n, long long m) {
    long long count = m / a + m / b + m / c;
    count -= m / lcm(a, b) + m / lcm(a, c) + m / lcm(b, c);
    count += m / lcm(a, lcm(b, c));
    return count < n;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, b, c, n;
    cin >> a >> b >> c >> n;

    long long l = 0, r = 1e9;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(a, b, c, n, m))
            l = m;
        else
            r = m;
    }

    cout << r;
}
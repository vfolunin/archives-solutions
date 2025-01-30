#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(long long n, long long a, long long b, long long t) {
    return t / a + t / b >= n;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n, a, b;
    cin >> n >> a >> b;
    n--;

    long long l = -1, r = 1;
    while (!can(n, a, b, r))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(n, a, b, m))
            r = m;
        else
            l = m;
    }

    cout << min(a, b) + r;
}
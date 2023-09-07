#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(long long n, long long a, long long b, long long w, long long h, long long d) {
    long long kw = w / (a + 2 * d);
    long long kh = h / (b + 2 * d);
    if (kw && (n + kw - 1) / kw <= kh)
        return 1;

    kw = w / (b + 2 * d);
    kh = h / (a + 2 * d);
    return kw && (n + kw - 1) / kw <= kh;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;

    long long l = 0, r = 1;
    while (can(n, a, b, w, h, r))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(n, a, b, w, h, m))
            l = m;
        else
            r = m;
    }

    cout << l;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long diff, l, r;
    cin >> diff >> l >> r;

    int res = 0;
    for (long long d = 1; d * d <= diff; d++) {
        if (diff % d)
            continue;

        long long d2 = diff / d;
        if ((d + d2) % 2 == 0) {
            long long x = (d + d2) / 2;
            long long y = d2 - x;
            res += l <= y * y && y * y <= x * x && x * x <= r;
        }
    }

    cout << res;
}
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

    long long n;
    cin >> n;

    if (!n) {
        cout << 0;
        return 0;
    }

    long long res = 1e18;
    for (long long d = 1; d * d <= abs(n); d++) {
        if (n % d)
            continue;

        long long d2 = n / d;
        if ((d + d2) % 2)
            continue;

        long long cur = (d + d2) / 2;
        if (cur >= 0)
            res = min(res, cur);

        if (n < 0) {
            cur = (-d + -d2) / 2;
            if (cur >= 0)
                res = min(res, cur);
        }
    }

    if (res != 1e18)
        cout << res;
    else
        cout << "none";
}
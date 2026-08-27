#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool check(int k1, int k0, int p, bool tail, unsigned long long l, unsigned long long r) {
    string s, block = string(k1, '1') + string(k0, '0');
    for (int i = 0; i < p; i++)
        s += block;
    if (tail)
        s += string(k1, '1');

    unsigned long long n = 0;
    for (char c : s)
        n = n * 2 + c - '0';
    return l <= n && n <= r;
}

bool solve() {
    unsigned long long l, r;
    if (!(cin >> l >> r))
        return 0;

    int res = 0;

    for (int k1 = 1; k1 < 64; k1++) {
        res += check(k1, 0, 1, 0, l, r);
        for (int k0 = 1; k0 < 64; k0++) {
            for (int p = 1; p < 64; p++) {
                if ((k1 + k0) * p < 64)
                    res += check(k1, k0, p, 0, l, r);
                if ((k1 + k0) * p + k1 < 64)
                    res += check(k1, k0, p, 1, l, r);
            }
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitsTo(int n) {
    int res = 0;
    for (int l = 1, r = 10, len = 1; l <= n; l *= 10, r *= 10, len++)
        res += (min(n + 1, r) - l) * len;
    return res;
}

int digits(int l, int r) {
    return digitsTo(r) - (l == 1 ? 0 : digitsTo(l - 1));
}

bool solve() {
    int from, to;
    cin >> from >> to;

    if (!from && !to)
        return 0;

    int l = from, r = to;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (digits(from, m) <= digits(m + 1, to))
            l = m;
        else
            r = m;
    }

    cout << l << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
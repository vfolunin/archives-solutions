#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int len;
    long long x;
    cin >> len >> x;

    long long limit = 1;
    for (int i = 0; i < len; i++)
        limit *= 10;

    long long res = x;
    for (int i = 0; i < 1e6; i++) {
        x *= x;
        while (x >= limit)
            x /= 10;
        res = max(res, x);
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
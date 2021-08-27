#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    b -= 2;

    long long n = a - b, res = 1e18;
    if (!n)
        res = a + 1;
    for (long long d = 1; d * d <= n; d++) {
        if (n % d)
            continue;
        if (a % d == b)
            res = min(res, d);
        if (a % (n / d) == b)
            res = min(res, n / d);
    }

    if (res == 1e18)
        cout << "Impossible\n";
    else
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
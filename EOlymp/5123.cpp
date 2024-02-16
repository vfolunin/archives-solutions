#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int test, n;
    cin >> test >> n;

    int res = n;
    while (n > 1) {
        if (n % 2)
            n = 3 * n + 1;
        else
            n /= 2;
        res = max(res, n);
    }

    cout << test << " " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
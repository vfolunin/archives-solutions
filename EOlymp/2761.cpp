#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int res = 2e9;
    for (int d = 1; d * d < n; d++) {
        if (n % d)
            continue;

        int d2 = n / d;
        if ((d2 - d) % 2 == 0)
            res = (d2 - d) / 2;
    }

    cout << (res != 2e9 ? res : -1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
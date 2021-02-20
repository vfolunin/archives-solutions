#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int codeLength, n;
    cin >> codeLength >> n;

    int res = 0;
    for (int bit = codeLength - 1; bit >= 0; bit--) {
        int part = 1 << bit;
        n %= 4 * part;
        if (part <= n && n < 3 * part)
            res |= 1 << bit;
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
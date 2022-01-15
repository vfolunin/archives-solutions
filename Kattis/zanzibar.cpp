#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int prev, cur = 1, res = 0;

    while (1) {
        prev = cur;
        cin >> cur;

        if (!cur)
            break;

        res += max(0, (cur - prev * 2));
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
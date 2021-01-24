#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<int> l(n), last(n + 1, 2e9);
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(last.begin() + 1, last.begin() + n, a[i]) - last.begin();
        last[pos] = a[i];
        l[i] = pos;
    }

    vector<int> r(n);
    fill(last.begin(), last.end(), 2e9);
    for (int i = n - 1; i >= 0; i--) {
        int pos = lower_bound(last.begin() + 1, last.begin() + n, a[i]) - last.begin();
        last[pos] = a[i];
        r[i] = pos;
    }

    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, 2 * min(l[i], r[i]) - 1);
    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
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

    vector<int> a;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        for (int j = l; j <= r; j++)
            a.push_back(j);
    }

    sort(a.begin(), a.end());

    int x;
    cin >> x;

    int l = lower_bound(a.begin(), a.end(), x) - a.begin();
    int r = upper_bound(a.begin(), a.end(), x) - a.begin();

    if (l < r)
        cout << x << " found from " << l << " to " << r - 1 << "\n";
    else
        cout << x << " not found\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
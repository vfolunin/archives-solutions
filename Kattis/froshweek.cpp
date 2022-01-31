#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long mergesort(vector<int> &a, vector<int> &t, int l, int r) {
    if (l == r)
        return 0;

    long long inv = 0;
    long long m = l + (r - l) / 2;
    inv += mergesort(a, t, l, m);
    inv += mergesort(a, t, m + 1, r);

    for (int i = l; i <= r; i++)
        t[i] = a[i];

    int ai = l, bi = m + 1;
    for (int i = l; i <= r; i++) {
        if (bi > r || ai <= m && t[ai] <= t[bi]) {
            a[i] = t[ai++];
        } else {
            inv += m - ai + 1;
            a[i] = t[bi++];
        }
    }

    return inv;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<int> t(n);

    cout << mergesort(a, t, 0, n - 1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}
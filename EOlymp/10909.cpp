#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long inversions(vector<int> &a, vector<int> &t, int l, int r) {
    if (l == r)
        return 0;

    int m = l + (r - l) / 2;
    long long res = 0;
    res += inversions(a, t, l, m);
    res += inversions(a, t, m + 1, r);

    for (int i = l; i <= r; i++)
        t[i] = a[i];

    int li = l, ri = m + 1;
    for (int i = l; i <= r; i++) {
        if (ri > r || li <= m && t[li] <= t[ri]) {
            a[i] = t[li++];
        } else {
            res += m - li + 1;
            a[i] = t[ri++];
        }
    }
    return res;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<int> t(n);
    int res = inversions(a, t, 0, n - 1) % 2;

    cout << (res ? "Marcelo\n" : "Carlos\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
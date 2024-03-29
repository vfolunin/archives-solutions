#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long mergeSort(vector<string> &a, vector<string> &t, int l, int r) {
    if (l == r)
        return 0;

    int m = l + (r - l) / 2;
    long long inversionCount = 0;
    inversionCount += mergeSort(a, t, l, m);
    inversionCount += mergeSort(a, t, m + 1, r);

    for (int i = l; i <= r; i++)
        t[i] = a[i];

    int ai = l, bi = m + 1;
    for (int i = l; i <= r; i++) {
        if (bi > r || ai <= m && t[ai] <= t[bi]) {
            a[i] = t[ai++];
        } else {
            inversionCount += m - ai + 1;
            a[i] = t[bi++];
        }
    }

    return inversionCount;
}

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    vector<string> a(size), t(size);
    for (string &x : a)
        cin >> x;

    cout << mergeSort(a, t, 0, size - 1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
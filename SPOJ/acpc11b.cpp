#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int aSize;
    cin >> aSize;

    vector<int> a(aSize);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());

    int bSize;
    cin >> bSize;

    vector<int> b(bSize);
    for (int &x : b)
        cin >> x;
    sort(b.begin(), b.end());

    int res = 1e9;
    for (int ai = 0, bi = 0; ai < aSize && bi < bSize; ) {
        res = min(res, abs(a[ai] - b[bi]));
        if (a[ai] < b[bi])
            ai++;
        else
            bi++;
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
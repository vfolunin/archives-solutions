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

    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());

    vector<int> b(n);
    for (int &x : b)
        cin >> x;
    sort(b.begin(), b.end());

    int res = 0;
    for (int i = 0; i < n; i++)
        res += a[i] * b[i];

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
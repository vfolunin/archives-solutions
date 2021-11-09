#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            res += a[i] > a[j];

    cout << "Optimal train swapping takes " << res << " swaps.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
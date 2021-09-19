#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, windowSize;
    cin >> size >> windowSize;

    vector<int> a(size);
    for (int &x : a)
        cin >> x;
    sort(a.begin(), a.end());

    int res = 1e9;
    for (int i = windowSize - 1; i < size; i++)
        res = min(res, a[i] - a[i - windowSize + 1]);

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
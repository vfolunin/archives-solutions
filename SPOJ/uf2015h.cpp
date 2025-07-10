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
    for (int &value : a)
        cin >> value;

    int cur = 0;
    for (int i = 0; i < windowSize; i++)
        cur += a[i];

    int res = cur;
    for (int i = windowSize; i < a.size(); i++) {
        cur += a[i] - a[i - windowSize];
        res = max(res, cur);
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
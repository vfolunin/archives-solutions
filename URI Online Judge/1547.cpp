#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, target;
    cin >> size >> target;

    vector<int> a(size);
    int res = 0;
    for (int i = 0; i < size; i++) {
        cin >> a[i];
        if (abs(a[i] - target) < abs(a[res] - target))
            res = i;
    }

    cout << res + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, threshold;
    cin >> size >> threshold;

    multiset<int> values;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        values.insert(value);
    }

    bool ok = 1;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        auto it = values.lower_bound(threshold - value);
        if (it == values.end())
            ok = 0;
        else
            values.erase(it);
    }

    cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
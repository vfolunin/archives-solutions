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

    set<int> values = { 1 };
    for (int i = 0; i < n - 1; i++) {
        int value = *values.begin();
        values.erase(values.begin());
        for (int factor : { 2, 3, 5 })
            values.insert(value * factor);
    }

    cout << *values.begin() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
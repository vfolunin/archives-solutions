#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long value;
    cin >> value;

    if (!value) {
        cout << "YES\n";
        return;
    }

    int last1 = -1, first0 = -1;
    for (int bit = 60; bit >= 0; bit--) {
        if (value & (1LL << bit))
            last1 = bit;
        else if (last1 != -1 && first0 == -1)
            first0 = bit;
    }

    cout << (last1 > first0 ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
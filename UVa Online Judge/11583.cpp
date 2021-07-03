#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int baseCount;
    cin >> baseCount;

    vector<int> bases(baseCount);
    for (int &base : bases) {
        string s;
        cin >> s;
        for (char c : s)
            base |= 1 << (c - 'a');
    }

    int res = 0, base = bases[0];
    for (int i = 1; i < baseCount; i++) {
        if (base & bases[i]) {
            base &= bases[i];
        } else {
            base = bases[i];
            res++;
        }
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
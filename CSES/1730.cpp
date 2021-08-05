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

    int xorSum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        xorSum ^= x;
    }

    cout << (xorSum ? "first" : "second") << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
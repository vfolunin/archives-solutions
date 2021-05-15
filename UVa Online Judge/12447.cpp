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

    int x = 0, mask = (1 << n) - 1;
    for (int i = 0; i < (1 << n); i++) {
        cout << x << "\n";

        int bit = 0;
        while (i & (1 << bit))
            bit++;
        x ^= mask ^ (1 << bit);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
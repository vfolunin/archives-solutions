#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    if (max(l1, l2) <= min(r1, r2))
        cout << max(l1, l2) << "\n";
    else
        cout << l1 + l2 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int i = 0; i < testCount; i++)
        solve();
}
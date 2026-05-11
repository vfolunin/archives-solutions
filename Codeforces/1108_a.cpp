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

    cout << l1 << " " << l2 + (l1 == l2) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}
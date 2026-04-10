#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    a2 -= a1;
    b2 -= b1;

    cout << (max(a1, b1) <= 2 * (min(a1, b1) + 1) &&
             max(a2, b2) <= 2 * (min(a2, b2) + 1) ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}
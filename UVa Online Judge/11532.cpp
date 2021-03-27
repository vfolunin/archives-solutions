#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int k1, k0;
    cin >> k1 >> k0;

    string s;
    while (k1 >= 2 && k0 >= 1) {
        k1 -= 2;
        k0 -= 1;
        s += "101";
    }
    if (k1 >= 1 && k0 >= 1) {
        k1 -= 1;
        k0 -= 1;
        s = "01" + s;
    }
    s = string(k0, '0') + s + string(k1, '1');

    long long res = 0;
    for (char c : s)
        res = res * 2 + c - '0';

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
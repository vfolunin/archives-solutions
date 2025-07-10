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

    int ad = abs(a1 - a2);
    ad = min(ad, 10 - ad);

    int bd = abs(b1 - b2);
    bd = min(bd, 10 - bd);

    cout << ad + bd << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double x, y;
    int candleCount;
    cin >> x >> y >> candleCount;

    bool found = 0;
    for (int i = 0; i < candleCount; i++) {
        double cx, cy;
        cin >> cx >> cy;
        found |= hypot(x - cx, y - cy) <= 8;
    }

    if (found)
        cout << "light a candle\n";
    else
        cout << "curse the darkness\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double h, w;
    cin >> h >> w;

    double l = 0, r = min(h, w) / 2;
    for (int i = 0; i < 300; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if ((h - 2 * m1) * (w - 2 * m1) * m1 <
            (h - 2 * m2) * (w - 2 * m2) * m2)
            l = m1;
        else
            r = m2;
    }

    cout << fixed << (h - 2 * l) * (w - 2 * l) * l << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
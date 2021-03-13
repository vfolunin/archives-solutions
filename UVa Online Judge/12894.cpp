#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int x1, y1, x2, y2, xc, yc, r;
    cin >> x1 >> y1 >> x2 >> y2 >> xc >> yc >> r;

    int h = y2 - y1, w = x2 - x1;
    int hc = yc - y1, wc = xc - x1;
    int unit = w / 10;

    if (h == unit * 6 && w == unit * 10 && r == unit * 2 && hc == unit * 3 && wc * 2 == unit * 9)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
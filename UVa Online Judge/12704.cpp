#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double x, y, r;
    cin >> x >> y >> r;

    double r1 = hypot(x, y);

    cout.precision(2);
    cout << fixed << r - r1 << " " << r + r1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
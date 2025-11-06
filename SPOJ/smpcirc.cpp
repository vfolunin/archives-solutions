#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

void solve() {
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    double d = hypot(x1 - x2, y1 - y2);

    if (d + r2 + EPS < r1 || d + r1 + EPS < r2)
        cout << "I\n";
    else if (abs(d + r2 - r1) < EPS || abs(d + r1 - r2) < EPS)
        cout << "E\n";
    else
        cout << "O\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
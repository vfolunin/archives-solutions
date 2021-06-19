#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<double, double> coords(long long n) {
    long long row = sqrt(n);
    while ((row + 2) * (row + 2) < n)
        row++;
    long long col = n - row * row;

    double x = (col - row) / 2.0;
    double y = row * sqrt(3) / 2 - (col % 2 ? sqrt(3) / 6 : 0);

    return { x, y };
}

bool solve() {
    int a, b;
    if (!(cin >> a >> b))
        return 0;

    auto [ax, ay] = coords(a);
    auto [bx, by] = coords(b);
    double res = hypot(ax - bx, ay - by);

    cout.precision(3);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    double cx = -ax, cy = ay, dx = bx, dy = -by;
    double p = hypot(ax - bx, ay - by) + hypot(cx - dx, cy - dy);

    cout.precision(3);
    cout << fixed << p << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
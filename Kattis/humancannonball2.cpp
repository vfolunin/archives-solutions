#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double v, angle, dist, h1, h2;
    cin >> v >> angle >> dist >> h1 >> h2;

    angle *= acos(-1) / 180;
    double t = dist / (v * cos(angle));
    double h = v * t * sin(angle) - 9.81 * t * t / 2;

    if (h1 + 1 <= h + 1e-9 && h - 1e-9 <= h2 - 1)
        cout << "Safe\n";
    else
        cout << "Not Safe\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double length, width, angle;
    cin >> length >> width >> angle;

    double coord = length * tan(angle / 180 * acos(-1));
    double dist1 = hypot(length, coord);

    int div = floor(coord / width);
    double mod = coord - div * width;
    coord = div % 2 ? width - mod : mod;
    double dist2 = hypot(length, coord);

    cout.precision(3);
    cout << fixed << dist1 / dist2 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
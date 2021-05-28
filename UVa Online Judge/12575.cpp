#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double a, b;
    cin >> a >> b;

    double angle = atan2(a, b);
    if (angle < 0)
        angle += 2 * acos(-1);

    cout.precision(2);
    cout << fixed << angle << " " << a * sin(angle) + b * cos(angle) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
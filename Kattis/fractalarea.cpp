#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double area(double radius, int level) {
    if (!level)
        return 0;
    return radius * radius + 3 * area(radius / 2, level - 1);
}

void solve() {
    int radius, level;
    cin >> radius >> level;

    cout << fixed << acos(-1) * (radius * radius + 4 * area(radius / 2.0, level - 1)) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
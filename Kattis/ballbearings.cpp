#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double outerDiameter, innerDiameter, spacing;
    cin >> outerDiameter >> innerDiameter >> spacing;

    double outerRadius = outerDiameter / 2;
    double innerRadius = innerDiameter / 2;
    double angle = 2 * asin((innerRadius + spacing / 2) / (outerRadius - innerRadius));

    cout << (int)floor(2 * acos(-1) / angle) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
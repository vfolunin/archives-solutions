#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double area(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void solve() {
    int sideCount;
    cin >> sideCount;

    vector<double> sides(sideCount);
    for (double &s : sides)
        cin >> s;
    sort(sides.begin(), sides.end());

    double maxArea = 0;
    for (int i = 0; i + 2 < sideCount; i++)
        if (sides[i] + sides[i + 1] > sides[i + 2])
            maxArea = max(maxArea, area(sides[i], sides[i + 1], sides[i + 2]));

    cout.precision(2);
    cout << fixed << maxArea << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
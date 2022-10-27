#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int pointCount;
    cin >> pointCount;

    vector<pair<int, int>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    sort(points.begin(), points.end(), [](auto &a, auto &b) {
        return a.first * a.first + a.second * a.second < b.first * b.first + b.second * b.second;
    });

    for (auto &[x, y] : points)
        cout << x << " " << y << "\n";
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
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

    sort(points.begin(), points.end());

    unordered_set<int> xs, ys;
    for (int i = 0; i + 1 < points.size(); i++) {
        if (points[i].first != points[i + 1].first)
            xs.insert(points[i + 1].first);
        else
            ys.insert(points[i + 1].second);
    }

    cout << xs.size() + ys.size() << "\n";
    for (int x : xs)
        cout << "x " << x << "\n";
    for (int y : ys)
        cout << "y " << y << "\n";
}
#include <iostream>
#include <algorithm>
#include <cmath>
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

    set<int> distances;
    for (int i = 0; i < points.size(); i++) {
        set<int> nextDistances;
        for (int j = 0; j < points.size(); j++) {
            if (i != j) {
                int dx = points[i].first - points[j].first;
                int dy = points[i].second - points[j].second;
                int distance = dx * dx + dy * dy;
                if (!i || distances.count(distance))
                    nextDistances.insert(distance);
            }
        }
        distances.swap(nextDistances);
    }

    cout << distances.size() << "\n";
    cout.precision(9);
    for (int distance : distances)
        cout << fixed << sqrt(distance) << "\n";
}
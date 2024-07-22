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

    int pointCount, dist;
    cin >> pointCount >> dist;

    vector<vector<pair<int, int>>> points(2);
    for (int i = 0; i < pointCount; i++) {
        int x, y, type;
        cin >> x >> y >> type;
        
        points[type].push_back({ x, y });
    }

    for (auto &[x0, y0] : points[0]) {
        for (auto &[x1, y1] : points[1]) {
            if ((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1) == dist * dist) {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
}
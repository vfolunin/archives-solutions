#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y, z;

    int floorDistTo(const Point &that) const {
        double dx = x - that.x, dy = y - that.y, dz = z - that.z;
        return floor(sqrt(dx * dx + dy * dy + dz * dz));
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<Point> points;
    while (1) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x || y || z)
            points.push_back({ x, y, z });
        else
            break;
    }

    vector<int> count(10);
    for (int i = 0; i < points.size(); i++) {
        int minDist = 1e9;
        for (int j = 0; j < points.size(); j++)
            if (i != j)
                minDist = min(minDist, points[i].floorDistTo(points[j]));
        if (minDist < 10)
            count[minDist]++;
    }

    for (int i = 0; i < 10; i++)
        cout << setw(4) << count[i];
    cout << "\n";
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y, z;
};

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool solve(int test) {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    map<pair<int, int>, vector<Point>> points;
    for (int i = 0; i < pointCount; i++) {
        Point p;
        cin >> p.x >> p.y >> p.z;

        int d = gcd(abs(p.x), abs(p.y));
        points[{p.x / d, p.y / d}].push_back(p);
    }

    vector<Point> unseenPoints;
    for (auto &[_, points] : points) {
        sort(points.begin(), points.end(), [](Point &a, Point &b) {
            return abs(a.x) + abs(a.y) < abs(b.x) + abs(b.y);
        });
        int z = -1;
        for (Point &p : points) {
            if (p.z <= z)
                unseenPoints.push_back(p);
            else
                z = p.z;
        }
    }

    sort(unseenPoints.begin(), unseenPoints.end(), [](Point &a, Point &b) {
        return a.x < b.x || a.x == b.x && a.y < b.y;
    });

    cout << "Data set " << test << ":\n";
    if (unseenPoints.empty()) {
        cout << "All the lights are visible.\n";
    } else {
        cout << "Some lights are not visible:\n";
        for (int i = 0; i < unseenPoints.size(); i++) {
            cout << "x = " << unseenPoints[i].x << ", y = " << unseenPoints[i].y;
            cout << (i + 1 < unseenPoints.size() ? ";\n" : ".\n");
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
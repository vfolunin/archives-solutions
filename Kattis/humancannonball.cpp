#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    double x, y;

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<Point> points(2);
    int size;
    cin >> points[0] >> points[1] >> size;

    for (int i = 0; i < size; i++)
        cin >> points.emplace_back();

    vector<vector<double>> dist(points.size(), vector<double>(points.size()));
    for (int a = 0; a < points.size(); a++) {
        for (int b = 0; b < points.size(); b++) {
            dist[a][b] = points[a].distanceTo(points[b]) / 5;
            if (a > 1)
                dist[a][b] = min(dist[a][b], abs(points[a].distanceTo(points[b]) - 50) / 5 + 2);
        }
    }

    for (int v = 0; v < points.size(); v++)
        for (int a = 0; a < points.size(); a++)
            for (int b = 0; b < points.size(); b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    cout << fixed << dist[0][1];
}
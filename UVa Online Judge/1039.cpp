#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;

    Point() {}

    Point(double x, double y) : x(x), y(y) {}

    double distanceTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }

    Point operator + (const Point &that) const {
        return Point(x + that.x, y + that.y);
    }

    Point operator * (double k) const {
        return Point(x * k, y * k);
    }
};

int getStation(Point &p, vector<Point> &stations) {
    int res = 0;
    for (int i = 1; i < stations.size(); i++)
        if (p.distanceTo(stations[i]) < p.distanceTo(stations[res]))
            res = i;
    return res;
}

int getWeight(Point &a, Point &b, vector<Point> &stations) {
    int sa = getStation(a, stations), sb = getStation(b, stations);
    if (sa == sb)
        return 0;
    if (a.distanceTo(b) < EPS)
        return 1;
    Point m = (a + b) * 0.5;
    return getWeight(a, m, stations) + getWeight(m, b, stations);
}

bool solve(int test) {
    int stationCount, cityCount, roadCount, queryCount;
    cin >> stationCount >> cityCount >> roadCount >> queryCount;

    if (!stationCount && !cityCount && !roadCount && !queryCount)
        return 0;

    vector<Point> stations(stationCount);
    for (auto &[x, y] : stations)
        cin >> x >> y;

    vector<Point> cities(cityCount);
    for (auto &[x, y] : cities)
        cin >> x >> y;

    vector<vector<int>> dist(cityCount, vector<int>(cityCount, 1e9));

    for (int v = 0; v < cityCount; v++)
        dist[v][v] = 0;

    for (int i = 0; i < roadCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        dist[a][b] = dist[b][a] = getWeight(cities[a], cities[b], stations);
    }

    for (int v = 0; v < cityCount; v++)
        for (int a = 0; a < cityCount; a++)
            for (int b = 0; b < cityCount; b++)
                dist[a][b] = min(dist[a][b], dist[a][v] + dist[v][b]);

    cout << "Case " << test << ":\n";

    for (int i = 0; i < queryCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (dist[a][b] == 1e9)
            cout << "Impossible\n";
        else
            cout << dist[a][b] << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
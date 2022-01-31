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
};

istream &operator >> (istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

void solve(int test) {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (Point &p : points)
        cin >> p;

    vector<int> used(n);
    vector<double> dist(n, 1e9);
    dist[0] = 0;

    double mstLength = 0;
    for (int i = 0; i < n; i++) {
        int p = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (p == -1 || dist[j] < dist[p]))
                p = j;

        used[p] = 1;
        mstLength += dist[p];

        for (int j = 0; j < n; j++)
            dist[j] = min(dist[j], points[p].distanceTo(points[j]));
    }

    if (test)
        cout << "\n";
    cout.precision(2);
    cout << fixed << mstLength << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}
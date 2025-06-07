#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;
};

struct Line {
    double a, b, c;

    int side(const Point &p) const {
        double r = a * p.x + b * p.y + c;
        if (abs(r) < EPS)
            return 0;
        else
            return r > 0 ? 1 : -1;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int pointCount, lineCount, radius;
    cin >> pointCount >> lineCount >> radius;

    vector<Point> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    vector<Line> lines(lineCount);
    for (auto &[a, b, c] : lines)
        cin >> a >> b >> c;

    set<vector<int>> s;

    for (Point &p : points) {
        vector<int> syndrome;
        for (Line l : lines)
            syndrome.push_back(l.side(p));

        s.insert(syndrome);
    }

    cout << (s.size() != pointCount ? "YES" : "NO");
}
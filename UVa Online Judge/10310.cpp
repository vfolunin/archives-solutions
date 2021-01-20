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

    double distTo(const Point &that) {
        return hypot(x - that.x, y - that.y);
    }
};

istream &operator >> (istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

bool solve() {
    int holeCount;
    Point gopher, dog;
    if (!(cin >> holeCount >> gopher >> dog))
        return 0;

    vector<Point> holes(holeCount);
    for (Point &hole : holes)
        cin >> hole;

    for (Point &hole : holes) {
        if (gopher.distTo(hole) * 2 <= dog.distTo(hole) + 1e-9) {
            cout << "The gopher can escape through the hole at (" << hole.x << "," << hole.y << ").\n";
            return 1;
        }
    }

    cout << "The gopher cannot escape.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout.precision(3);
    cout << fixed;
    while (solve());
}
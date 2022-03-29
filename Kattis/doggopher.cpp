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

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Point gopher, dog;
    cin >> gopher >> dog;

    vector<Point> holes;
    Point hole;
    while (cin >> hole)
        holes.push_back(hole);

    for (Point &hole : holes) {
        if (gopher.distTo(hole) * 2 <= dog.distTo(hole) + 1e-9) {
            cout.precision(3);
            cout << "The gopher can escape through the hole at (" << fixed << hole.x << "," << hole.y << ").\n";
            return 0;
        }
    }

    cout << "The gopher cannot escape.\n";
}
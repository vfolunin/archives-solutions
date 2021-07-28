#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-8;

struct Point {
    double x, y, z;

    Point() {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y), z(b.z - a.z) {}

    double length() const {
        return hypot(hypot(x, y), z);
    }
};

bool solve() {
    int sourceCount, targetCount;
    cin >> sourceCount >> targetCount;

    if (!sourceCount && !targetCount)
        return 0;

    vector<Point> source(sourceCount);
    for (auto &[x, y, z] : source)
        cin >> x >> y >> z;

    double r = 40000 / (2 * acos(-1));
    int res = 0;

    for (int i = 0; i < targetCount; i++) {
        Point target;
        cin >> target.x >> target.y >> target.z;

        for (Point &s : source) {
            double a = r, b = Point(s, target).length(), c = s.length();
            if (a * a + b * b <= c * c + EPS) {
                res++;
                break;
            }
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;

    double distance2To(const Point &that) const {
        int dx = x - that.x;
        int dy = y - that.y;
        return dx * dx + dy * dy;
    }

    friend istream &operator >> (istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<Point> hits(5);
    for (Point &hit : hits)
        cin >> hit;

    int res = 0;
    for (int x = 0; x <= 100; x += 25) {
        Point target = { x, 0 };
        for (Point &hit : hits) {
            if (target.distance2To(hit) <= 100) {
                res++;
                break;
            }
        }
    }

    cout << res;
}
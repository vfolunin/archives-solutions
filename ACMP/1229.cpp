#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;

    int distance2To(const Point &that) const {
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

    Point a, b, c;
    cin >> a >> b >> c;

    vector<int> dist = { a.distance2To(b), a.distance2To(c), b.distance2To(c) };
    sort(dist.begin(), dist.end());

    cout << (dist[0] + dist[1] == dist[2] ? "Yes" : "No");
}
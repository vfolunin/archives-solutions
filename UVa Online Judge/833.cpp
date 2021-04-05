#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;
};

istream &operator >> (istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

struct Segment {
    Point a, b;
};

istream &operator >> (istream &in, Segment &s) {
    in >> s.a >> s.b;
    if (s.a.x > s.b.x)
        swap(s.a, s.b);
    return in;
}

void solve(int test) {
    int segmentCount;
    cin >> segmentCount;

    vector<Segment> segments(segmentCount);
    for (Segment &s : segments)
        cin >> s;

    int pointCount;
    cin >> pointCount;

    if (test)
        cout << "\n";

    for (int i = 0; i < pointCount; i++) {
        Point p;
        cin >> p;

        while (1) {
            int si = -1;
            double dist;

            for (int j = 0; j < segmentCount; j++) {
                if (p.x < segments[j].a.x || p.x > segments[j].b.x)
                    continue;
                double dx = segments[j].b.x - segments[j].a.x;
                double dy = segments[j].b.y - segments[j].a.y;
                double y = segments[j].a.y + (p.x - segments[j].a.x) / dx * dy;
                if (y >= p.y)
                    continue;
                if (si == -1 || dist > p.y - y) {
                    si = j;
                    dist = p.y - y;
                }
            }

            if (si == -1)
                break;
            p = (segments[si].a.y < segments[si].b.y ? segments[si].a : segments[si].b);
        }

        cout << p.x << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}
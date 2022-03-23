#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Circle {
    double cx, cy, r;
    string color;

    bool contains(double x, double y) {
        return hypot(cx - x, cy - y) <= r;
    }
};

void solve() {
    int circleCount;
    cin >> circleCount;

    vector<Circle> circles(circleCount);
    for (auto &[cx, cy, r, color] : circles) {
        cin >> cx >> cy >> r >> color;
        r = sqrt(r / acos(-1));
    }
    reverse(circles.begin(), circles.end());

    int pointCount;
    cin >> pointCount;

    for (int i = 0; i < pointCount; i++) {
        double x, y;
        cin >> x >> y;

        bool found = 0;
        for (Circle &circle : circles) {
            if (circle.contains(x, y)) {
                cout << circle.color << "\n";
                found = 1;
                break;
            }
        }

        if (!found)
            cout << "white\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Triangle {
    vector<double> side;

    Triangle(double a, double b, double c) {
        side = { a, b, c };
        sort(side.begin(), side.end());
        for (int i = 0; i < 3; i++)
            side[i] /= side[2];
    }

    bool operator < (const Triangle &that) const {
        for (int i = 0; i < 3; i++)
            if (fabs(side[i] - that.side[i]) > 1e-6)
                return side[i] < that.side[i];
        return 0;
    }
};

void rec(const Triangle &t, set<Triangle> &triangles) {
    if (triangles.count(t))
        return;
    triangles.insert(t);

    double median = sqrt(2 * t.side[0] * t.side[0] + 2 * t.side[1] * t.side[1] - t.side[2] * t.side[2]) / 2;
    rec(Triangle(t.side[0], median, t.side[2] / 2), triangles);
    rec(Triangle(t.side[1], median, t.side[2] / 2), triangles);
}

void solve() {
    double a, b, c;
    cin >> a >> b >> c;

    set<Triangle> triangles;
    rec(Triangle(a, b, c), triangles);

    cout << triangles.size() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
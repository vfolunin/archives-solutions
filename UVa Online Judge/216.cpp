#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Point {
    int x, y;

    double distTo(const Point &that) const {
        return hypot(x - that.x, y - that.y);
    }
};

istream &operator >> (istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

ostream &operator << (ostream &out, Point &p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

bool solve(int test) {
    int pointCount;
    cin >> pointCount;

    if (!pointCount)
        return 0;

    vector<Point> points(pointCount);
    for (Point &point : points)
        cin >> point;
    
    vector<int> order;
    for (int i = 0; i < pointCount; i++)
        order.push_back(i);

    double bestLength = 1e9;
    vector<int> bestOrder;
    do {
        double length = 0;
        for (int i = 1; i < pointCount; i++)
            length += points[order[i - 1]].distTo(points[order[i]]) + 16;
        if (length < bestLength) {
            bestLength = length;
            bestOrder = order;
        }
    } while (next_permutation(order.begin(), order.end()));

    cout << string(58, '*') << "\n";
    cout << "Network #" << test << "\n";
    for (int i = 1; i < pointCount; i++) {
        Point &a = points[bestOrder[i - 1]], &b = points[bestOrder[i]];
        cout << "Cable requirement to connect " << a << " to " << b;
        cout << " is " << a.distTo(b) + 16 << " feet.\n";
    }
    cout << "Number of feet of cable required is " << bestLength << ".\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cout << fixed;
    cout.precision(2);

    for (int test = 1; solve(test); test++);
}
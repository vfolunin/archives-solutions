#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Circle {
    double x, y, radius;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int circleCount;
    double time;
    cin >> circleCount >> time;

    vector<Circle> circles(circleCount);
    for (auto &[x, y, radius] : circles)
        cin >> x >> y >> radius;

    for (int i = 0; i < circleCount; i++) {
        for (int j = i + 1; j < circleCount; j++) {
            double dist = hypot(circles[i].x - circles[j].x, circles[i].y - circles[j].y);
            time = min(time, (dist - circles[i].radius - circles[j].radius) / 2);
        }
    }

    cout << fixed << time;
}
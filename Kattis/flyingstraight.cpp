#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double speed1, speed2, time;
    cin >> speed1 >> speed2 >> time;

    double radius = 6378137;
    double circleLength = 2 * acos(-1) * radius;
    double circleTime = circleLength / speed2;
    double angle = fmod(time, circleTime) / circleTime * 2 * acos(-1);

    double x1 = radius, y1 = speed1 * time;
    double x2 = radius * cos(angle), y2 = radius * sin(angle);

    cout << fixed << hypot(x1 - x2, y1 - y2);
}
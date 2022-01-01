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

    int circleCount, pointCount;
    cin >> circleCount >> pointCount;

    vector<double> circles(circleCount);
    for (double &r : circles)
        cin >> r;

    long long score = 0;
    for (int i = 0; i < pointCount; i++) {
        double x, y;
        cin >> x >> y;
        score += circles.end() - lower_bound(circles.begin(), circles.end(), hypot(x, y));
    }

    cout << score << "\n";
}
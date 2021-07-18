#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double PI = acos(-1);

bool solve() {
    int planetCount, time;
    if (!(cin >> planetCount >> time))
        return 0;

    double x = 0, y = 0;
    for (int i = 0; i < planetCount; i++) {
        double radius, period;
        cin >> radius >> period;

        double angle = time / period * 2 * PI;
        double nextX = x + radius * cos(angle);
        double nextY = y + radius * sin(angle);

        cout.precision(4);
        cout << fixed << hypot(nextX, nextY) << (i + 1 < planetCount ? " " : "\n");

        x = nextX;
        y = nextY;
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
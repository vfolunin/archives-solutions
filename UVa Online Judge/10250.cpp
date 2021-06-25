#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double ax, ay, bx, by;
    if (!(cin >> ax >> ay >> bx >> by))
        return 0;

    double vx = (bx - ax) / 2, vy = (by - ay) / 2;
    double ox = ax + vx, oy = ay + vy;
    double cx = ox - vy, cy = oy + vx;
    double dx = ox + vy, dy = oy - vx;

    cout.precision(10);
    cout << fixed << cx << " " << cy << " " << dx << " " << dy << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
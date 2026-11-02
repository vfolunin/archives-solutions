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

    double speed, angle, delta;
    cin >> speed >> angle >> delta;
    angle = angle * 3.1415926535 / 180;

    double res = 0;
    while (1) {
        double dist = speed * speed * sin(2 * angle) / 10;
        if (abs(dist) < 1e-9)
            break;

        res += dist;
        speed = sqrt(speed * speed / delta);
    }

    cout.precision(2);
    cout << fixed << res;
}
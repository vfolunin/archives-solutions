#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double rad(double deg) {
    return deg / 180 * acos(-1);
}

void solve() {
    int commandCount;
    cin >> commandCount;

    int angle = 0;
    double x = 0, y = 0;

    for (int i = 0; i < commandCount; i++) {
        string command;
        int arg;
        cin >> command >> arg;

        if (command == "lt") {
            angle = (angle + arg % 360) % 360;
        } else if (command == "rt") {
            angle = (angle - arg % 360 + 360) % 360;
        } else if (command == "fd") {
            x += arg * cos(rad(angle));
            y += arg * sin(rad(angle));
        } else {
            x -= arg * cos(rad(angle));
            y -= arg * sin(rad(angle));
        }
    }

    cout.precision(0);
    cout << fixed << hypot(x, y) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
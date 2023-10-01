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

    int pointCount;
    cin >> pointCount;

    cout << "YES\n";
    for (int i = 0; i < pointCount; i++) {
        double angle = 2 * acos(-1) * i / pointCount;
        int x = 1e4 * cos(angle);
        int y = 1e4 * sin(angle);

        cout << x << " " << y << "\n";
    }
}
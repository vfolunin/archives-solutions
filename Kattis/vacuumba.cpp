#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int segmentCount;
    cin >> segmentCount;

    double angle = asin(1), x = 0, y = 0;

    for (int i = 0; i < segmentCount; i++) {
        double rotation, distance;
        cin >> rotation >> distance;

        angle += rotation / 180 * acos(-1);
        x += distance * cos(angle);
        y += distance * sin(angle);
    }

    cout << fixed << x << " " << y << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
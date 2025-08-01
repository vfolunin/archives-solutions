#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int segmentCount;
    cin >> segmentCount;

    double res = 1e9;
    for (int i = 0; i < segmentCount; i++) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }

        if (x2 < -1e-9 || 1e-9 < x1)
            continue;

        double y = y1 + (y2 - y1) / (x2 - x1) * -x1;

        if (y >= 0 && res > y)
            res = y;
    }

    cout << fixed << (res != 1e9 ? res : -1);
}
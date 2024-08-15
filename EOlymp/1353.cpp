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

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int pointCount = 100;
    vector<int> res(4);

    for (int i = 0; i <= pointCount; i++) {
        double x = x1 + (x2 - x1) * i / pointCount;
        double y = y1 + (y2 - y1) * i / pointCount;

        res[0] |= x > 0 && y > 0;
        res[1] |= x < 0 && y > 0;
        res[2] |= x < 0 && y < 0;
        res[3] |= x > 0 && y < 0;
    }

    bool found = 0;
    for (int i = 0; i < res.size(); i++) {
        if (res[i]) {
            cout << i + 1 << "\n";
            found = 1;
        }
    }

    if (!found)
        cout << 0;
}
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

    int rectangleCount;
    cin >> rectangleCount;

    int minX = 1e9, minY = 1e9, maxX = -1e9, maxY = -1e9;
    for (int i = 0; i < rectangleCount; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        minX = min({ minX, x1, x2 });
        minY = min({ minY, y1, y2 });
        maxX = max({ maxX, x1, x2 });
        maxY = max({ maxY, y1, y2 });
    }

    cout << 1LL * (maxX - minX) * (maxY - minY);
}
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

    int rectangleCount, minX, minY, maxX, maxY;
    cin >> rectangleCount >> minX >> minY >> maxX >> maxY;

    for (int i = 1; i < rectangleCount; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        minX = max(minX, x1);
        minY = max(minY, y1);
        maxX = min(maxX, x2);
        maxY = min(maxY, y2);
    }

    if (minX <= maxX && minY <= maxY)
        cout << (maxX - minX) * (maxY - minY);
    else
        cout << 0;
}
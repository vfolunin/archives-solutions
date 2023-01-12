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

    int h, w;
    cin >> h >> w;

    int minValue = 1e9, minY, minX;
    int maxValue = -1e9, maxY, maxX;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int value;
            cin >> value;

            if (minValue > value) {
                minValue = value;
                minY = y;
                minX = x;
            }
            if (maxValue < value) {
                maxValue = value;
                maxY = y;
                maxX = x;
            }
        }
    }

    cout << minY + 1 << " " << minX + 1 << " " << minValue << "\n";
    cout << maxY + 1 << " " << maxX + 1 << " " << maxValue;
}
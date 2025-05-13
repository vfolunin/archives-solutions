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

    int size = 0;
    cin >> size;

    int minX = 2e9, minY = 2e9, maxX = -2e9, maxY = -2e9;
    for (int i = 0; i < size; i++) {
        int x, y;
        cin >> x >> y;

        minX = min(minX, x);
        minY = min(minY, y);
        maxX = max(maxX, x);
        maxY = max(maxY, y);
    }

    cout << minX << " " << minY << " " << maxX << " " << maxY;
}
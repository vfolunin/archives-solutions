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

    int w, h, r, size;
    cin >> w >> h >> r >> size;

    int minY = h, minX = w, maxY = 0, maxX = 0;
    for (int i = 0; i < size; i++) {
        int x, y;
        cin >> x >> y;

        minY = min(minY, y - r);
        minX = min(minX, x - r);
        maxY = max(maxY, y + r);
        maxX = max(maxX, x + r);
    }

    cout << h * w - (maxY - minY) * (maxX - minX);
}
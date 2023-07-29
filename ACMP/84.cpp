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

    int minY = h, maxY = -1, minX = w, maxX = -1;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            char c;
            cin >> c;

            if (c == '*') {
                minY = min(minY, y);
                maxY = max(maxY, y);
                minX = min(minX, x);
                maxX = max(maxX, x);
            }
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            cout << (minY <= y && y <= maxY && minX <= x && x <= maxX ? "*" : ".");
        cout << "\n";
    }
}
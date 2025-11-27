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

    int queryCount, h, w;
    cin >> queryCount >> h >> w;

    for (int i = 0; i < queryCount; i++) {
        int minY = 1e9, maxY = -1e9;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                char c;
                cin >> c;

                if (c == '#') {
                    minY = min(minY, y);
                    maxY = max(maxY, y);
                }
            }
        }

        cout << maxY - minY << "\n";
    }
}
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

    int h, w, startCount;
    cin >> h >> w >> startCount;

    vector<pair<int, int>> start(startCount);
    for (auto &[startY, startX] : start) {
        cin >> startY >> startX;
        startY--;
        startX--;
    }

    int maxDist = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int dist = 1e9;
            for (auto &[startY, startX] : start)
                dist = min(dist, abs(y - startY) + abs(x - startX));
            maxDist = max(maxDist, dist);
        }
    }

    cout << maxDist;
}
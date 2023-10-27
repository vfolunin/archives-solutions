#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const vector<int> DY = { -2, -2, -1, 1, 2, 2, 1, -1 };
const vector<int> DX = { -1, 1, 2, 2, 1, -1, -2, -2 };

bool rec(int y, int x, int targetY, int targetX, vector<pair<int, int>> &path) {
    if (y == targetY && x == targetX)
        return 1;
    if (path.size() > 5)
        return 0;

    for (int d = 0; d < DY.size(); d++) {
        int ty = y + DY[d];
        int tx = x + DX[d];

        path.push_back({ ty, tx });

        if (rec(ty, tx, targetY, targetX, path))
            return 1;

        path.pop_back();
    }
    
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int targetY, targetX;
    cin >> targetY >> targetX;

    int y = 0, x = 0;

    while (abs(y - targetY) > 2 || abs(x - targetX) > 2) {
        int bestDist = 1e9, bestD;

        for (int d = 0; d < DY.size(); d++) {
            int ty = y + DY[d];
            int tx = x + DX[d];
            int dist = abs(ty - targetY) + abs(tx - targetX);

            if (bestDist > dist) {
                bestDist = dist;
                bestD = d;
            }
        }

        y += DY[bestD];
        x += DX[bestD];

        cout << y << " " << x << "\n";
    }

    vector<pair<int, int>> path;
    rec(y, x, targetY, targetX, path);

    for (auto &[y, x] : path)
        cout << y << " " << x << "\n";
}
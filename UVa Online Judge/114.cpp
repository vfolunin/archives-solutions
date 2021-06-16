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

    int width, height, wallCost, bumperCount;
    cin >> width >> height >> wallCost >> bumperCount;

    map<pair<int, int>, int> bumperBonus, bumperCost;
    for (int i = 0; i < bumperCount; i++) {
        int x, y;
        cin >> x >> y >> bumperBonus[{x, y}] >> bumperCost[{x, y}];
    }

    int dy[] = {0, 1, 0, -1};
    int dx[] = {1, 0, -1, 0};

    int x, y, d, life, totalBonus = 0;
    while (cin >> x >> y >> d >> life) {
        int bonus = 0;

        while (--life > 0) {
            int tx = x + dx[d];
            int ty = y + dy[d];

            if (tx <= 1 || tx >= width || ty <= 1 || ty >= height) {
                life -= wallCost;
                d = (d + 3) % 4;
            } else if (bumperBonus.count({ tx, ty })) {
                bonus += bumperBonus[{tx, ty}];
                life -= bumperCost[{tx, ty}];
                d = (d + 3) % 4;
            } else {
                x = tx;
                y = ty;
            }
        }

        totalBonus += bonus;
        cout << bonus << "\n";
    }

    cout << totalBonus << "\n";
}
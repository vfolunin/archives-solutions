#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int x, y, d;
    if (!(cin >> x >> y >> d))
        return 0;

    set<pair<int, int>> land;
    for (int i = 0; i < 8; i++) {
        int tx, ty, type;
        cin >> tx >> ty >> type;

        if (type)
            land.insert({ tx, ty });
    }

    int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
    int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

    for (int i = 6; i < 14; i++) {
        int tx = x + dx[(d + i) % 8];
        int ty = y + dy[(d + i) % 8];

        if (land.count({ tx, ty })) {
            cout << (d + i) % 8 << "\n";
            break;
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
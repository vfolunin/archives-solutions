#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int w, h;
    cin >> w >> h;

    if (!w && !h)
        return 0;

    vector<vector<long long>> paths(h + 1, vector<long long>(w + 1));

    int wolfLocationsCount;
    cin >> wolfLocationsCount;

    for (int i = 0; i < wolfLocationsCount; i++) {
        int x, y;
        cin >> x >> y;
        paths[y][x] = -1;
    }

    if (paths[0][0] != -1)
        paths[0][0] = 1;

    for (int y = 0; y <= h; y++) {
        for (int x = 0; x <= w; x++) {
            if (paths[y][x] != -1) {
                if (y)
                    paths[y][x] += paths[y - 1][x];
                if (x)
                    paths[y][x] += paths[y][x - 1];
            } else {
                paths[y][x] = 0;
            }
        }
    }

    int res = paths[h][w];
    if (res == 0)
        cout << "There is no path.\n";
    else if (res == 1)
        cout << "There is one path from Little Red Riding Hood's house to her grandmother's house.\n";
    else
        cout << "There are " << res << " paths from Little Red Riding Hood's house to her grandmother's house.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
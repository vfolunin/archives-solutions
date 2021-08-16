#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool dfs(int y, int x, int t, int fy, int fx, vector<vector<int>> &wall, vector<vector<int>> &dist, vector<vector<int>> &path) {
    dist[y][x] = t;
    if (y == fy && x == fx) {
        path[y][x] = 1;
        return 1;
    }

    static int dy[] = { 0, -1, 0, 1 };
    static int dx[] = { -1, 0, 1, 0 };

    for (int d = 0; d < 4; d++) {
        int ty = y + dy[d], tx = x + dx[d];

        if (ty < 0 || ty >= wall.size() || tx < 0 || tx >= wall[0].size() ||
            d == 0 && (wall[y][x - 1] & 1) || d == 1 && (wall[y - 1][x] & 2) ||
            d == 2 && (wall[y][x] & 1) || d == 3 && (wall[y][x] & 2) || dist[ty][tx])
            continue;

        if (dfs(ty, tx, t + 1, fy, fx, wall, dist, path)) {
            path[y][x] = 1;
            return 1;
        }
    }

    return 0;
}

bool solve(int test) {
    int h, w, sy, sx, fy, fx;
    cin >> h >> w >> sy >> sx >> fy >> fx;

    if (!h && !w)
        return 0;

    sy--;
    sx--;
    fy--;
    fx--;

    vector<vector<int>> wall(h, vector<int>(w));
    for (vector<int> &row : wall)
        for (int &x : row)
            cin >> x;

    vector<vector<int>> dist(h, vector<int>(w));
    vector<vector<int>> path(h, vector<int>(w));
    dfs(sy, sx, 1, fy, fx, wall, dist, path);

    cout << "Maze " << test << "\n\n";

    cout << "+";
    for (int x = 0; x < w; x++)
        cout << "---+";
    cout << "\n";

    for (int y = 0; y < h; y++) {
        cout << "|";
        for (int x = 0; x < w; x++) {
            if (dist[y][x]) {
                if (path[y][x])
                    cout << setw(3) << dist[y][x];
                else
                    cout << "???";
            } else {
                cout << "   ";
            }
            cout << ((wall[y][x] & 1) || x + 1 == w ? "|" : " ");
        }
        cout << "\n";

        cout << "+";
        for (int x = 0; x < w; x++)
            cout << ((wall[y][x] & 2) || y + 1 == h ? "---+" : "   +");
        cout << "\n";
    }
    
    cout << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
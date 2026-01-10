#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int y, int x, int finishY, int finishX, vector<vector<int>> &visited,
    vector<pair<int, int>> &path, vector<vector<pair<int, int>>> &paths) {
    path.push_back({ x, y });
    visited[y][x] = 1;

    if (y == finishY && x == finishX) {
        if (paths.empty() || paths.back().size() == path.size())
            paths.push_back(path);
        else if (paths.back().size() > path.size())
            paths = { path };
    } else if (paths.empty() || paths.back().size() > path.size()) {
        static vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
        static vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < visited.size() && 0 <= tx && tx < visited.size() && !visited[ty][tx])
                rec(ty, tx, finishY, finishX, visited, path, paths);
        }
    }

    visited[y][x] = 0;
    path.pop_back();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    vector<vector<int>> visited(8, vector<int>(8));
    vector<pair<int, int>> path;
    vector<vector<pair<int, int>>> paths;
    rec(y1 - '1', x1 - 'a', y2 - '1', x2 - 'a', visited, path, paths);
    sort(paths.begin(), paths.end());

    for (vector<pair<int, int>> &path : paths)
        for (int i = 0; i < path.size(); i++)
            cout << (char)(path[i].first + 'a') << (char)(path[i].second + '1') << (i + 1 < path.size() ? " -> " : "\n");
}
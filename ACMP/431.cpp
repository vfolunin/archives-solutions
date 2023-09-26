#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void bfs(vector<string> &a, int startY, int startX, int finishY, int finishX) {
    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
    vector<vector<pair<int, int>>> from(a.size(), vector<pair<int, int>>(a[0].size(), { -1, -1 }));
    queue<pair<int, int>> q;

    dist[startY][startX] = 0;
    q.push({ startY, startX });

    vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
    vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != '#' && dist[ty][tx] > dist[y][x] + 1) {
                dist[ty][tx] = dist[y][x] + 1;
                from[ty][tx] = { y, x };
                q.push({ ty, tx });
            }
        }
    }

    if (dist[finishY][finishX] == 1e9) {
        cout << "Impossible";
        return;
    }

    for (int y = finishY, x = finishX; y != startY || x != startX; ) {
        a[y][x] = '@';
        auto &[py, px] = from[y][x];
        y = py;
        x = px;
    }

    for (string &row : a)
        cout << row << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<string> a(size);
    int startY = -1, startX = -1;
    int finishY, finishX;

    for (int y = 0; y < size; y++) {
        cin >> a[y];
        for (int x = 0; x < size; x++) {
            if (a[y][x] == '@') {
                if (startY == -1) {
                    startY = y;
                    startX = x;
                } else {
                    finishY = y;
                    finishX = x;
                }
            }
        }
    }

    bfs(a, startY, startX, finishY, finishX);
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(int startY, int startX, int finishY, int finishX) {
    vector<vector<int>> dist(9, vector<int>(9, 1e9));
    queue<pair<int, int>> q;

    dist[startY][startX] = 0;
    q.push({ startY, startX });

    vector<int> d1y = { -2, -2, -1, 1, 2, 2, 1, -1 };
    vector<int> d1x = { -1, 1, 2, 2, 1, -1, -2, -2 };
    vector<int> d0y = { -1, -1, 1, 1 };
    vector<int> d0x = { -1, 1, 1, -1 };

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        if (y == finishY && x == finishX)
            return dist[y][x];

        if ((y + x) % 2) {
            for (int d = 0; d < d1y.size(); d++) {
                int ty = y + d1y[d];
                int tx = x + d1x[d];

                if (0 <= ty && ty < dist.size() && 0 <= tx && tx < dist.size() && dist[ty][tx] > dist[y][x] + 1) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push({ ty, tx });
                }
            }
        } else {
            for (int d = 0; d < d0y.size(); d++) {
                for (int step = 1; step < dist.size(); step++) {
                    int ty = y + d0y[d] * step;
                    int tx = x + d0x[d] * step;

                    if (0 <= ty && ty < dist.size() && 0 <= tx && tx < dist.size() && dist[ty][tx] > dist[y][x] + 1) {
                        dist[ty][tx] = dist[y][x] + 1;
                        q.push({ ty, tx });
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    string start, finish;
    cin >> start >> finish;

    cout << bfs(start[1] - '1', start[0] - 'A', finish[1] - '1', finish[0] - 'A');
}
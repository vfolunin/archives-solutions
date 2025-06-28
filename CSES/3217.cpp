#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> bfs(int size) {
    vector<vector<int>> dist(size, vector<int>(size, 1e9));
    queue<pair<int, int>> q;

    dist[0][0] = 0;
    q.push({ 0, 0 });

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        static vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
        static vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < size && 0 <= tx && tx < size && dist[ty][tx] > dist[y][x] + 1) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push({ ty, tx });
            }
        }
    }

    return dist;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<int>> dist = bfs(size);

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            cout << dist[y][x] << " ";
        cout << "\n";
    }
}
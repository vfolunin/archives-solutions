#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<vector<int>> &a) {
    int h = a.size(), w = a[0].size();

    vector<vector<int>> dist(h, vector<int>(w, 1e9));
    queue<pair<int, int>> q;

    dist[0][0] = 0;
    q.push({ 0, 0 });

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };

        for (int d = 0; d < dy.size(); d++) {
            int s;
            for (s = 1; 1; s++) {
                int ty = y + dy[d] * s;
                int tx = x + dx[d] * s;

                if (ty < 0 || ty >= h || tx < 0 || tx >= w || a[ty][tx] == 1)
                    break;

                if (a[ty][tx] == 2)
                    return dist[y][x] + 1;
            }

            s--;
            int ty = y + dy[d] * s;
            int tx = x + dx[d] * s;

            if (dist[ty][tx] > dist[y][x] + 1) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push({ ty, tx });
            }
        }
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    cout << bfs(a);
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<string> &a, int sy, int sx, int fy, int fx) {
    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
    deque<int> q;

    dist[sy][sx] = 0;
    q.push_back(sy);
    q.push_back(sx);

    static int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    static int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

    while (!q.empty()) {
        int y = q.front();
        q.pop_front();
        int x = q.front();
        q.pop_front();

        for (int d = 0; d < 8; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size()) {
                if (d == a[y][x] - '0' && dist[ty][tx] > dist[y][x]) {
                    dist[ty][tx] = dist[y][x];
                    q.push_front(tx);
                    q.push_front(ty);
                } else if (d != a[y][x] - '0' && dist[ty][tx] > dist[y][x] + 1) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push_back(ty);
                    q.push_back(tx);
                }
            }
        }
    }

    return dist[fy][fx];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int sy, sx, fy, fx;
        cin >> sy >> sx >> fy >> fx;

        cout << bfs(a, sy - 1, sx - 1, fy - 1, fx - 1) << "\n";
    }
}
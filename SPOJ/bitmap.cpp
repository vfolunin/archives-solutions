#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> bfs(int h, int w, vector<pair<int, int>> &start) {
    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<int> q;

    for (auto &[y, x] : start) {
        dist[y][x] = 0;
        q.push(y);
        q.push(x);
    }

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        static int dy[] = { -1, 0, 1, 0 };
        static int dx[] = { 0, 1, 0, -1 };

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < h && 0 <= tx && tx < w && dist[ty][tx] == -1) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push(ty);
                q.push(tx);
            }
        }
    }

    return dist;
}

void solve() {
    int h, w;
    cin >> h >> w;

    vector<pair<int, int>> start;
    for (int y = 0; y < h; y++) {
        string line;
        cin >> line;
        for (int x = 0; x < w; x++)
            if (line[x] == '1')
                start.push_back({ y, x });
    }

    vector<vector<int>> dist = bfs(h, w, start);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            cout << dist[y][x] << " ";
        cout << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
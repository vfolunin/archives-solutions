#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int w, h, restrictionCount;
    if (!(cin >> w >> h >> restrictionCount))
        return 0;

    int dy[] = { 0, -1, 0, 1, 0 };
    int dx[] = { 0, 0, 1, 0, -1 };

    vector<vector<vector<pair<int, int>>>> graph(h, vector<vector<pair<int, int>>>(w));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            for (int d = 0; d < 5; d++) {
                int ty = y + dy[d], tx = x + dx[d];
                if (0 <= ty && ty < h && 0 <= tx && tx < w)
                    graph[y][x].push_back({ ty, tx });
            }
        }
    }

    for (int i = 0; i < restrictionCount; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        graph[y1][x1].erase(find(graph[y1][x1].begin(), graph[y1][x1].end(), make_pair(y2, x2)));
    }

    int monitorCount;
    cin >> monitorCount;

    vector<pair<int, int>> monitor(501, { -1, -1 });
    for (int i = 0; i < monitorCount; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        monitor[t] = { y, x };
    }

    set<vector<int>> visited = { { 0, 0, 0 } };
    queue<int> q;
    q.push(0);
    q.push(0);
    q.push(0);

    while (1) {
        int t = q.front();
        q.pop();
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        if (monitor[t] == make_pair(y, x))
            continue;

        if (y == h - 1 && x == w - 1) {
            cout << t << "\n";
            break;
        }

        for (auto &[ty, tx] : graph[y][x]) {
            if (!visited.count({ t + 1, ty, tx })) {
                visited.insert({ t + 1, ty, tx });
                q.push(t + 1);
                q.push(ty);
                q.push(tx);
            }
        }
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
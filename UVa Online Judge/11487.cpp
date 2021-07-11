#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

const int MOD = 20437;

pair<int, int> bfs(vector<string> &a, vector<pair<int, int>> coords, int index) {
    vector<vector<int>> dist(a.size(), vector<int>(a.size(), -1));
    vector<vector<int>> paths(a.size(), vector<int>(a.size()));
    queue<int> q;

    auto &[sy, sx] = coords[index];
    dist[sy][sx] = 0;
    paths[sy][sx] = 1;
    q.push(sy);
    q.push(sx);

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        static int dy[] = { -1, 0, 1, 0 };
        static int dx[] = { 0, 1, 0, -1 };

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a.size() &&
                (a[ty][tx] == '.' || a[ty][tx] != '#' && a[ty][tx] <= 'A' + index + 1)) {
                if (dist[ty][tx] == -1) {
                    dist[ty][tx] = dist[y][x] + 1;
                    paths[ty][tx] = paths[y][x];
                    q.push(ty);
                    q.push(tx);
                } else if (dist[ty][tx] == dist[y][x] + 1) {
                    paths[ty][tx] = (paths[ty][tx] + paths[y][x]) % MOD;
                }
            }
        }
    }

    auto &[fy, fx] = coords[index + 1];
    return { dist[fy][fx], paths[fy][fx] };
}

bool solve(int test) {
    int size;
    cin >> size;

    if (!size)
        return 0;

    vector<string> a(size);
    vector<pair<int, int>> coords;
    for (int i = 0; i < size; i++) {
        cin >> a[i];
        for (int j = 0; j < size; j++) {
            if (isalpha(a[i][j])) {
                coords.resize(max<int>(coords.size(), a[i][j] - 'A' + 1));
                coords[a[i][j] - 'A'] = { i, j };
            }
        }
    }

    int dist = 0, paths = 1;
    for (int i = 0; i + 1 < coords.size(); i++) {
        auto [d, p] = bfs(a, coords, i);
        dist += d;
        paths = paths * p % MOD;
    }

    cout << "Case " << test << ": ";
    if (paths)
        cout << dist << " " << paths << "\n";
    else
        cout << "Impossible\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
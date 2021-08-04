#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> bfs(vector<string> &a, int sy, int sx) {
    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
    queue<int> q;

    dist[sy][sx] = 0;
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
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == '.' && dist[ty][tx] == 1e9) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push(ty);
                q.push(tx);
            }
        }
    }

    return dist;
}

bool solve() {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    vector<string> a(h);
    vector<pair<int, int>> points(1);
    
    for (int y = 0; y < h; y++) {
        cin >> a[y];
        for (int x = 0; x < w; x++) {
            if (a[y][x] == '@') {
                points[0] = { y, x };
                a[y][x] = '.';
            }

            if (a[y][x] == '!') {
                points.push_back({ y, x });
                a[y][x] = '.';
            }
        }
    }

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] == '*') {
                static int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
                static int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

                for (int d = 0; d < 8; d++) {
                    int ty = y + dy[d], tx = x + dx[d];
                    if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] == '.')
                        a[ty][tx] = 'X';
                }
            }
        }
    }

    vector<vector<int>> dist(points.size(), vector<int>(points.size()));
    for (int i = 0; i < points.size(); i++) {
        vector<vector<int>> d = bfs(a, points[i].first, points[i].second);
        for (int j = 0; j < points.size(); j++)
            dist[i][j] = d[points[j].first][points[j].second];
    }

    vector<int> p;
    for (int i = 0; i <= points.size(); i++)
        p.push_back(i % points.size());

    long long res = 1e9;
    do {
        long long cur = 0;
        for (int i = 0; i + 1 < p.size() && cur < res; i++)
            cur += dist[p[i]][p[i + 1]];
        res = min(res, cur);
    } while (next_permutation(p.begin() + 1, p.end() - 1));

    cout << (res != 1e9 ? res : -1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
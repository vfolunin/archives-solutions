#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> bfs(vector<string> &a, int y, int x) {
    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
    queue<int> q;

    dist[y][x] = 0;
    q.push(y);
    q.push(x);

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
        int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

        for (int d = 0; d < 8; d++) {
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

void solve() {
    int limit;
    cin >> limit;

    vector<string> a(8);
    vector<pair<int, int>> points(1);
    for (int y = 0; y < 8; y++) {
        cin >> a[y];
        for (int x = 0; x < 8; x++) {
            if (a[y][x] == 'k') {
                points[0] = { y, x };
                a[y][x] = '.';
            }
            if (a[y][x] == 'P') {
                points.push_back({ y, x });
                a[y][x] = '.';
            }
        }
    }

    vector<vector<int>> dist(points.size(), vector<int>(points.size()));
    for (int i = 0; i < points.size(); i++) {
        vector<vector<int>> d = bfs(a, points[i].first, points[i].second);
        for (int j = i + 1; j < points.size(); j++)
            dist[i][j] = dist[j][i] = d[points[j].first][points[j].second];
    }

    vector<int> p(points.size());
    for (int i = 0; i < p.size(); i++)
        p[i] = i;

    do {
        int len = 0;
        for (int i = 1; i < p.size(); i++)
            len += dist[p[i - 1]][p[i]];
        if (len <= limit) {
            cout << "Yes\n";
            return;
        }
    } while (next_permutation(p.begin() + 1, p.end()));

    cout << "No\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
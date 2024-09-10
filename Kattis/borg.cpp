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
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == ' ' && dist[ty][tx] == 1e9) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push(ty);
                q.push(tx);
            }
        }
    }

    return dist;
}

struct DSU {
    vector<int> id;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
    }
};

struct Edge {
    int a, b, w;

    bool operator < (const Edge &that) const {
        return w < that.w;
    }
};

void solve() {
    int h, w;
    cin >> w >> h;
    cin.ignore();

    vector<string> a(h);
    vector<pair<int, int>> points(1);

    for (int y = 0; y < h; y++) {
        getline(cin, a[y]);
        a[y] += string(w - a[y].size(), '#');

        for (int x = 0; x < w; x++) {
            if (a[y][x] == 'S') {
                points[0] = { y, x };
                a[y][x] = ' ';
            }

            if (a[y][x] == 'A') {
                points.push_back({ y, x });
                a[y][x] = ' ';
            }
        }
    }

    vector<Edge> edges;
    for (int i = 0; i < points.size(); i++) {
        vector<vector<int>> d = bfs(a, points[i].first, points[i].second);
        for (int j = i + 1; j < points.size(); j++)
            edges.push_back({ i, j, d[points[j].first][points[j].second] });
    }

    sort(edges.begin(), edges.end());
    DSU dsu(points.size());

    int mstWeight = 0;
    for (auto &[a, b, w] : edges) {
        if (!dsu.connected(a, b)) {
            dsu.merge(a, b);
            mstWeight += w;
        }
    }

    cout << mstWeight << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
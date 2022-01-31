#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> bfs(vector<string> &a, vector<pair<int, int>> &s) {
    int h = a.size(), w = a[0].size();
    vector<vector<int>> dist(h, vector<int>(w, 1e9));
    queue<int> q;

    for (auto &[si, sj] : s) {
        dist[si][sj] = 0;
        q.push(si);
        q.push(sj);
    }

    while (!q.empty()) {
        int i = q.front();
        q.pop();
        int j = q.front();
        q.pop();

        static int di[] = { -1, 0, 1, 0 };
        static int dj[] = { 0, 1, 0, -1 };

        for (int d = 0; d < 4; d++) {
            int ti = i + di[d];
            int tj = j + dj[d];
            if (0 <= ti && ti < h && 0 <= tj && tj < w && a[ti][tj] != '#' && dist[ti][tj] == 1e9) {
                dist[ti][tj] = dist[i][j] + 1;
                q.push(ti);
                q.push(tj);
            }
        }
    }

    return dist;
}

void solve() {
    int height, width;
    cin >> height >> width;

    vector<string> a(height);
    vector<pair<int, int>> s, f;

    for (int i = 0; i < height; i++) {
        cin >> a[i];
        for (int j = 0; j < width; j++) {
            if (a[i][j] == 'J')
                s.push_back({ i, j });
            if (a[i][j] == 'F')
                f.push_back({ i, j });
        }
    }

    vector<vector<int>> distS = bfs(a, s);
    vector<vector<int>> distF = bfs(a, f);

    int res = 1e9;
    for (int i = 0; i < height; i++) {
        if (a[i][0] != '#' && distS[i][0] < distF[i][0])
            res = min(res, distS[i][0]);
        if (a[i][width - 1] != '#' && distS[i][width - 1] < distF[i][width - 1])
            res = min(res, distS[i][width - 1]);
    }
    for (int j = 0; j < width; j++) {
        if (a[0][j] != '#' && distS[0][j] < distF[0][j])
            res = min(res, distS[0][j]);
        if (a[height - 1][j] != '#' && distS[height - 1][j] < distF[height - 1][j])
            res = min(res, distS[height - 1][j]);
    }

    if (res != 1e9)
        cout << res + 1 << "\n";
    else
        cout << "IMPOSSIBLE\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}
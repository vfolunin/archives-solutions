#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    vector<string> a(size);
    for (string &row : a)
        cin >> row;

    int h = size, w = a[0].size();

    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<int> q;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '3') {
                dist[i][j] = 0;
                q.push(i);
                q.push(j);
            }
        }
    }

    static int di[] = { -1, 0, 1, 0 };
    static int dj[] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        int i = q.front();
        q.pop();
        int j = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ti = i + di[d], tj = j + dj[d];
            if (0 <= ti && ti < h && 0 <= tj && tj < w && dist[ti][tj] == -1) {
                dist[ti][tj] = dist[i][j] + 1;
                q.push(ti);
                q.push(tj);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (a[i][j] == '1')
                res = max(res, dist[i][j]);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
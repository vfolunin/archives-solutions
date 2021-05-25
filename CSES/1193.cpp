#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

const vector<int> DY = { -1, 0, 1, 0 };
const vector<int> DX = { 0, 1, 0, -1 };
const string DC = "URDL";

pair<vector<vector<int>>, vector<vector<int>>> bfs(vector<string> &a, int y, int x) {
    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), -1));
    vector<vector<int>> pred(a.size(), vector<int>(a[0].size(), -1));
    queue<int> q;

    dist[y][x] = 0;
    q.push(y);
    q.push(x);

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ty = y + DY[d], tx = x + DX[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != '#' && dist[ty][tx] == -1) {
                dist[ty][tx] = dist[y][x] + 1;
                pred[ty][tx] = d;
                q.push(ty);
                q.push(tx);
            }
        }
    }

    return { dist, pred };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    int ay, ax, by, bx;

    vector<string> a(h);
    for (int y = 0; y < h; y++) {
        cin >> a[y];
        if (int x = a[y].find('A'); x != -1) {
            ay = y;
            ax = x;
        }
        if (int x = a[y].find('B'); x != -1) {
            by = y;
            bx = x;
        }
    }

    auto [dist, pred] = bfs(a, ay, ax);

    if (dist[by][bx] == -1) {
        cout << "NO";
        return 0;
    }

    string path;
    for (int y = by, x = bx; y != ay || x != ax; ) {
        int d = pred[y][x];
        path += DC[d];
        y -= DY[d];
        x -= DX[d];
    }
    reverse(path.begin(), path.end());

    cout << "YES\n" << path.size() << "\n" << path;
}
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

pair<vector<vector<int>>, vector<vector<int>>> bfs(vector<string> &a, char c) {
    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
    vector<vector<int>> pred(a.size(), vector<int>(a[0].size(), -1));
    queue<int> q;

    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a[0].size(); x++) {
            if (a[y][x] == c) {
                dist[y][x] = 0;
                q.push(y);
                q.push(x);
            }
        }
    }

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ty = y + DY[d], tx = x + DX[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != '#' && dist[ty][tx] == 1e9) {
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

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    auto [aDist, aPred] = bfs(a, 'A');
    auto [mDist, _] = bfs(a, 'M');

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y != 0 && y != h - 1 && x != 0 && x != w - 1 || a[y][x] == '#' || aDist[y][x] >= mDist[y][x])
                continue;

            string path;
            while (a[y][x] != 'A') {
                int d = aPred[y][x];
                path += DC[d];
                y -= DY[d];
                x -= DX[d];
            }
            reverse(path.begin(), path.end());

            cout << "YES\n" << path.size() << "\n" << path << "\n";
            return 0;
        }
    }

    cout << "NO";
}
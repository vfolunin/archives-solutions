#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <tuple>
using namespace std;

vector<vector<vector<int>>> bfs(vector<string> &a, int startY, int startX) {
    vector dist(a.size(), vector(a[0].size(), vector<int>(8, 1e9)));
    deque<tuple<int, int, int>> q;

    static vector<int> dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
    static vector<int> dx = { -1, 0, 1, 1, 1, 0, -1, -1 };

    for (int d = 0; d < dy.size(); d++) {
        dist[startY][startX][d] = 1;
        q.push_back({ startY, startX, d });
    }

    while (!q.empty()) {
        auto [y, x, d] = q.front();
        q.pop_front();

        for (int td = 0; td < dy.size(); td++) {
            if (td != d && dist[y][x][td] == 1e9) {
                dist[y][x][td] = dist[y][x][d] + 1;
                q.push_back({ y, x, td });
            }
        }

        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() &&
            a[ty][tx] == '.' && dist[ty][tx][d] > dist[y][x][d]) {
            dist[ty][tx][d] = dist[y][x][d];
            q.push_front({ ty, tx, d });
        }
    }

    return dist;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (string &s : a)
        cin >> s;

    int startY, startX;
    cin >> startX >> startY;
    startY = h - startY;
    startX--;

    vector<vector<vector<int>>> dist = bfs(a, startY, startX);

    int finishY, finishX;
    cin >> finishX >> finishY;
    finishY = h - finishY;
    finishX--;

    int res = 1e9;
    for (int dist : dist[finishY][finishX])
        res = min(res, dist);

    cout << (res != 1e9 ? res : -1);
}
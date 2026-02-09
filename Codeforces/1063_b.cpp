#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, startY, startX, limitL, limitR;
    cin >> h >> w >> startY >> startX >> limitL >> limitR;
    startY--;
    startX--;

    vector<string> a(h);
    for (string &s : a)
        cin >> s;

    vector dist(h, vector<pair<int, int>>(w, { 1e9, 1e9 }));
    set<tuple<int, int, int, int>> q;

    dist[startY][startX] = { 0, 0 };
    q.insert({ 0, 0, startY, startX });

    while (!q.empty()) {
        auto [distL, distR, y, x] = *q.begin();
        q.erase(q.begin());

        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };

        for (int d = 0; d < dy.size(); d++) {
            int tDistL = distL + (dx[d] == -1);
            int tDistR = distR + (dx[d] == 1);
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] != '*' &&
                tDistL <= limitL && tDistR <= limitR &&
                dist[ty][tx] > make_pair(tDistL, tDistR)) {
                q.erase({ dist[ty][tx].first, dist[ty][tx].second, ty, tx });
                dist[ty][tx] = { tDistL, tDistR };
                q.insert({ dist[ty][tx].first, dist[ty][tx].second, ty, tx });
            }
        }
    }

    int res = 0;
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            res += dist[y][x].first != 1e9;

    cout << res;
}
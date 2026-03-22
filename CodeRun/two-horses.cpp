#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <tuple>
using namespace std;

int bfs(int y1, int x1, int y2, int x2) {
    vector<vector<vector<vector<int>>>> dist(8, vector<vector<vector<int>>>(8, vector<vector<int>>(8, vector<int>(8, 1e9))));
    queue<tuple<int, int, int, int>> q;

    dist[y1][x1][y2][x2] = 0;
    q.push({ y1, x1, y2, x2 });

    while (!q.empty()) {
        auto [y1, x1, y2, x2] = q.front();
        q.pop();

        if (y1 == y2 && x1 == x2)
            return dist[y1][x1][y2][x2];

        static vector<int> dy = { -2, -1, 1, 2, 2, 1, -1, -2 };
        static vector<int> dx = { 1, 2, 2, 1, -1, -2, -2, -1 };

        for (int d1 = 0; d1 < dy.size(); d1++) {
            int ty1 = y1 + dy[d1];
            int tx1 = x1 + dx[d1];
            if (ty1 < 0 || ty1 > 7 || tx1 < 0 || tx1 > 7)
                continue;

            for (int d2 = 0; d2 < dy.size(); d2++) {
                int ty2 = y2 + dy[d2];
                int tx2 = x2 + dx[d2];
                if (ty2 < 0 || ty2 > 7 || tx2 < 0 || tx2 > 7)
                    continue;

                if (dist[ty1][tx1][ty2][tx2] > dist[y1][x1][y2][x2] + 1) {
                    dist[ty1][tx1][ty2][tx2] = dist[y1][x1][y2][x2] + 1;
                    q.push({ ty1, tx1, ty2, tx2 });
                }
            }
        }
    }

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    cin >> a >> b;

    cout << bfs(a[0] - 'a', a[1] - '1', b[0] - 'a', b[1] - '1');
}
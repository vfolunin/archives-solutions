#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    int startY, startX, finishY, finishX;
    for (int y = 0; y < h; y++) {
        cin >> a[y];
        if (int x = a[y].find('A'); x != -1) {
            startY = y;
            startX = x;
        }
        if (int x = a[y].find('B'); x != -1) {
            finishY = y;
            finishX = x;
        }
    }

    vector<vector<int>> dist(h, vector<int>(w, -1));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] == 'Z') {
                dist[y][x] = -2;
                static int dy[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
                static int dx[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
                for (int d = 0; d < 8; d++) {
                    int ty = y + dy[d], tx = x + dx[d];
                    if (0 <= ty && ty < h && 0 <= tx && tx < w)
                        dist[ty][tx] = -2;
                }
            }
        }
    }
    dist[startY][startX] = 0;
    dist[finishY][finishX] = -1;

    queue<int> q;
    q.push(startY);
    q.push(startX);

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        static int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
        static int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
        for (int d = 0; d < 8; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < h && 0 <= tx && tx < w && dist[ty][tx] == -1) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push(ty);
                q.push(tx);
            }
        }
    }

    if (dist[finishY][finishX] == -1)
        cout << "King Peter, you can't go now!\n";
    else
        cout << "Minimal possible length of a trip is " << dist[finishY][finishX] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
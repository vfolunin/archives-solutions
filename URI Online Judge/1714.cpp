#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<string> &a, int mask) {
    if (islower(a[0][0]) && !(mask & (1 << (a[0][0] - 'a'))) ||
        isupper(a[0][0]) && (mask & (1 << (a[0][0] - 'A'))))
        return 1e9;

    queue<int> q;
    q.push(0);
    q.push(0);

    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
    dist[0][0] = 1;

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && dist[ty][tx] == 1e9 &&
                (islower(a[ty][tx]) && (mask & (1 << (a[ty][tx] - 'a'))) ||
                    isupper(a[ty][tx]) && !(mask & (1 << (a[ty][tx] - 'A'))))) {
                q.push(ty);
                q.push(tx);
                dist[ty][tx] = dist[y][x] + 1;
            }
        }
    }

    return dist[a.size() - 1][a[0].size() - 1];
}

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    vector<string> a(size);
    for (string &row : a)
        cin >> row;

    int res = 1e9;
    for (int mask = 0; mask < (1 << 10); mask++)
        res = min(res, bfs(a, mask));

    cout << (res != 1e9 ? res : -1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    solve();
}
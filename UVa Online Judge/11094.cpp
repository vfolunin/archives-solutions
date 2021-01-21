#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<string> &a, int y, int x, char land) {
    a[y][x] = 0;
    queue<int> q;
    q.push(y);
    q.push(x);    

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    int res = 1;
    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = (x + dx[d] + a[0].size()) % a[0].size();
            if (0 <= ty && ty < a.size() && a[ty][tx] == land) {
                res++;
                a[ty][tx] = 0;
                q.push(ty);
                q.push(tx);
            }
        }
    }

    return res;
}

bool solve() {
    int h, w;
    if (!(cin >> h >> w))
        return 0;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;
    
    int y, x;
    cin >> y >> x;
    char land = a[y][x];
    bfs(a, y, x, land);

    int res = 0;
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            if (a[y][x] == land)
                res = max(res, bfs(a, y, x, land));    

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
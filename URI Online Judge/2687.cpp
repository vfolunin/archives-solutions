#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<vector<int>> &a, int y, int x) {
    queue<int> q;
    q.push(y);
    q.push(x);
    a[y][x] = 1;
    int size = 0;

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();
        size++;

        static int dy[] = { -1, 0, 1, 0 };
        static int dx[] = { 0, 1, 0, -1 };

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && !a[ty][tx]) {
                q.push(ty);
                q.push(tx);
                a[ty][tx] = 1;
            }
        }
    }

    return size;
}

void solve() {
    int size;
    cin >> size;
    size += 2;

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 1; y + 1 < size; y++)
        for (int x = 1; x + 1 < size; x++)
            cin >> a[y][x];

    cout.precision(2);
    cout << fixed << (size * size - bfs(a, 0, 0)) / 2.0 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
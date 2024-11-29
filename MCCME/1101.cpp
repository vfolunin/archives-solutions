#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &a, int y, int x, vector<vector<int>> &visited) {
    vector<pair<int, int>> stack = { { y, x } };

    while (!stack.empty()) {
        auto &[y, x] = stack.back();

        visited[y][x] = 1;

        static vector<int> dy = { 0, -1, 0, 1 };
        static vector<int> dx = { 1, 0, -1, 0 };

        int ty = y + dy[a[y][x]];
        int tx = x + dx[a[y][x]];

        if (ty < 0 || ty == a.size() || tx < 0 || tx == a[0].size() || visited[ty][tx] == 2) {
            while (!stack.empty()) {
                visited[stack.back().first][stack.back().second] = 2;
                stack.pop_back();
            }
        } else if (visited[ty][tx] == 1) {
            stack.pop_back();
        } else {
            stack.push_back({ ty, tx });
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            a[y][x]--;
        }
    }

    int res = 0;
    vector<vector<int>> visited(h, vector<int>(w));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (!visited[y][x])
                dfs(a, y, x, visited);
            res += visited[y][x] == 1;
        }
    }

    cout << res;
}
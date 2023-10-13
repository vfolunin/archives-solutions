#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<string> &a, int y, int x, vector<vector<int>> &visited) {
    visited[y][x] = 1;

    static vector<int> dy = { -1, 0, 1, 0 };
    static vector<int> dx = { 0, 1, 0, -1 };

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != a[y][x] && !visited[ty][tx])
            dfs(a, ty, tx, visited);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> a(8);
    for (string &row : a)
        cin >> row;

    vector<vector<int>> visited(a.size(), vector<int>(a[0].size()));
    int res = 0;

    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a[0].size(); x++) {
            if (!visited[y][x]) {
                dfs(a, y, x, visited);
                res++;
            }
        }
    }

    cout << res;
}
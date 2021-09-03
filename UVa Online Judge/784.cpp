#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<string> &a, int y, int x) {
    a[y][x] = '#';

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    for (int d = 0; d < 4; d++) {
        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[ty].size() && a[ty][tx] == ' ')
            dfs(a, ty, tx);
    }
}

void solve() {
    vector<string> a;
    int sy, sx;

    for (int y = 0; 1; y++) {
        string line;
        getline(cin, line);
        a.push_back(line);

        if (line[0] == '_')
            break;

        if (int x = line.find('*'); x != -1) {
            sy = y;
            sx = x;
        }
    }

    dfs(a, sy, sx);

    for (string &row : a)
        cout << row << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}
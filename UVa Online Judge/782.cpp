#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void addSpaces(vector<string> &a, int width) {
    for (string &line : a)
        line += string(width - line.size(), ' ');
}

void removeSpaces(vector<string> &a) {
    for (string &line : a)
        while (!line.empty() && line.back() == ' ')
            line.pop_back();
}

void dfs(vector<string> &a, int y, int x, vector<vector<int>> &visited) {
    visited[y][x] = 1;
    
    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    for (int d = 0; d < 4; d++) {
        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[ty].size()) {
            if (a[ty][tx] == ' ' && !visited[ty][tx])
                dfs(a, ty, tx, visited);
            if (a[ty][tx] != ' ' && a[ty][tx] != '#' && a[ty][tx] != '_')
                a[y][x] = '#';
        }
    }
}

void solve() {
    vector<string> a;
    int sy, sx, maxWidth = 0;

    for (int y = 0; 1; y++) {
        string line;
        getline(cin, line);

        a.push_back(line);
        if (int x = line.find('*'); x != -1) {
            sy = y;
            sx = x;
        }
        maxWidth = max<int>(maxWidth, line.size());

        if (!line.empty() && line[0] == '_')
            break;
    }

    a[sy][sx] = ' ';
    addSpaces(a, maxWidth + 1);
    vector<vector<int>> visited(a.size(), vector<int>(a[0].size()));
    dfs(a, sy, sx, visited);

    removeSpaces(a);

    for (string line : a)
        cout << line << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; i++)
        solve();
}
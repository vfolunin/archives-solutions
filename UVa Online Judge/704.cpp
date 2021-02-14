#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<string> a;
    while (1) {
        string line;
        getline(cin, line);
        a.push_back(line);
        if (line[0] == '_')
            break;
    }

    int sy, sx;
    for (int y = 0; y < a.size(); y++) {
        int x = a[y].find('*');
        if (x != -1) {
            sy = y;
            sx = x;
            break;
        }
    }

    queue<int> q;
    q.push(sy);
    q.push(sx);
    a[sy][sx] = '#';

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        static int dy[] = { -1, 0, 1, 0 };
        static int dx[] = { 0, 1, 0, -1 };

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[y].size() && a[ty][tx] == ' ') {
                q.push(ty);
                q.push(tx);
                a[ty][tx] = '#';
            }
        }
    }

    for (string &line : a)
        cout << line << "\n";
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
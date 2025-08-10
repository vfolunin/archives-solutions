#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool bfs(vector<string> &a) {
    vector<vector<int>> visited(a.size(), vector<int>(a[0].size()));
    queue<pair<int, int>> q;

    visited[0][0] = 1;
    q.push({ 0, 0 });

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        if (y == a.size() - 1 && x == a[0].size() - 1)
            return 1;

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != '#' && !visited[ty][tx]) {
                visited[ty][tx] = 1;
                q.push({ ty, tx });
            }
        }
    }

    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    const long long MOD = (1LL << 31) - 1;
    vector<vector<long long>> ways(size, vector<long long>(size));
    ways[0][0] = 1;

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (a[y][x] == '#')
                continue;

            if (y)
                ways[y][x] = (ways[y][x] + ways[y - 1][x]) % MOD;
            if (x)
                ways[y][x] = (ways[y][x] + ways[y][x - 1]) % MOD;
        }
    }

    if (ways.back().back())
        cout << ways.back().back() << "\n";
    else if (bfs(a))
        cout << "THE GAME IS A LIE\n";
    else
        cout << "INCONCEIVABLE\n";
}
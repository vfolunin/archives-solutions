#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int bfs(vector<string> &a, int price) {
    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
    set<pair<int, pair<int, int>>> q;

    for (int y = 0; y < a.size(); y++) {
        if (int x = a[y].find('S'); x != -1) {
            dist[y][x] = 0;
            q.insert({ dist[y][x], { y, x } });
            break;
        }
    }

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    while (!q.empty()) {
        auto [y, x] = q.begin()->second;
        q.erase(q.begin());

        if (!y || y + 1 == a.size() || !x || x + 1 == a[0].size())
            return dist[y][x] + 1;

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != '#' &&
                dist[ty][tx] > dist[y][x] + (a[ty][tx] == '@' ? price : 1)) {
                dist[ty][tx] = dist[y][x] + (a[ty][tx] == '@' ? price : 1);
                q.insert({ dist[ty][tx], { ty, tx } });
            }
        }
    }

    return -1;
}

void solve() {
    int h, w, price;
    cin >> h >> w >> price;
    price++;

    vector<string> a(h);
    for (string &s : a)
        cin >> s;

    cout << bfs(a, price) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
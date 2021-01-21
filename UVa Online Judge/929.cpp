#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int dijkstra(vector<vector<int>> &a) {
    int h = a.size(), w = a[0].size();
    vector<vector<int>> dist(h, vector<int>(w, 1e9));
    dist[0][0] = a[0][0];
    set<pair<int, pair<int, int>>> q = { {0, {0, 0}} }; 

    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };
    
    while (!q.empty()) {
        auto [y, x] = q.begin()->second;
        q.erase(q.begin());

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < h && 0 <= tx && tx < w && dist[ty][tx] > dist[y][x] + a[ty][tx]) {
                q.erase({ dist[ty][tx], {ty, tx} });
                dist[ty][tx] = dist[y][x] + a[ty][tx];
                q.insert({ dist[ty][tx], {ty, tx} });
            }
        }
    }

    return dist[h - 1][w - 1];
}

void solve(int test) {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (vector<int> &row : a)
        for (int &x : row)
            cin >> x;

    cout << dijkstra(a) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
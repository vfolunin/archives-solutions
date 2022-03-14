#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if (a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

pair<int, vector<pair<int, int>>> bfs(int y, int x) {
    vector<vector<int>> dist(8, vector<int>(8, 1e9));
    queue<int> q;

    dist[y][x] = 0;
    q.push(y);
    q.push(x);

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        static int dy[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
        static int dx[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

        for (int d = 0; d < 8; d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            if (0 <= ty && ty < dist.size() && 0 <= tx && tx < dist.size() && dist[ty][tx] == 1e9) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push(ty);
                q.push(tx);
            }
        }
    }

    int maxDist = 0;
    for (int y = 0; y < dist.size(); y++)
        for (int x = 0; x < dist.size(); x++)
            maxDist = max(maxDist, dist[y][x]);

    vector<pair<int, int>> mostDistant;
    for (int y = 0; y < dist.size(); y++)
        for (int x = 0; x < dist.size(); x++)
            if (dist[y][x] == maxDist)
                mostDistant.push_back({ y, x });

    sort(mostDistant.begin(), mostDistant.end(), compare);
    return { maxDist, mostDistant };
}

void solve() {
    char x, y;
    cin >> x >> y;
    x -= 'a';
    y -= '1';

    auto [maxDistance, mostDistant] = bfs(y, x);

    cout << maxDistance;
    for (auto &[y, x] : mostDistant)
        cout << " " << (char)(x + 'a') << (char)(y + '1');
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
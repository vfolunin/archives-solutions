#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, string> dijkstra(vector<string> &a, int startY, int startX, int finishY, int finishX) {
    vector<vector<int>> dist(a.size(), vector<int>(a[0].size(), 1e9));
    vector<vector<pair<char, pair<int, int>>>> from(a.size(), vector<pair<char, pair<int, int>>>(a[0].size()));
    set<pair<int, pair<int, int>>> q;

    dist[startY][startX] = 0;
    q.insert({ dist[startY][startX], { startY, startX } });

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };
    string dc = "NESW";

    while (!q.empty()) {
        auto [y, x] = q.begin()->second;
        q.erase(q.begin());

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] != '#') {
                int weight = a[ty][tx] == '.' ? 1 : 2;
                if (dist[ty][tx] > dist[y][x] + weight) {
                    q.erase({ dist[ty][tx], { ty, tx } });
                    dist[ty][tx] = dist[y][x] + weight;
                    from[ty][tx] = { dc[d], { y, x } };
                    q.insert({ dist[ty][tx], { ty, tx } });
                }
            }
        }
    }

    if (dist[finishY][finishX] == 1e9)
        return { -1, "" };

    string path;
    if (dist[finishY][finishX] != 1e9) {
        for (int y = finishY, x = finishX; y != startY || x != startX; ) {
            path += from[y][x].first;
            auto [py, px] = from[y][x].second;
            y = py;
            x = px;
        }
    }
    reverse(path.begin(), path.end());
    return { dist[finishY][finishX], path };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, startY, startX, finishY, finishX;
    cin >> h >> w >> startY >> startX >> finishY >> finishX;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    auto [dist, path] = dijkstra(a, startY - 1, startX - 1, finishY - 1, finishX - 1);

    cout << dist << "\n" << path;
}
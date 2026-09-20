#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> bfs(vector<string> &plan, int startY, int startX) {
    vector<vector<int>> dist(plan.size(), vector<int>(plan[0].size(), 1e8));
    deque<pair<int, int>> q;

    dist[startY][startX] = 0;
    q.push_back({ startY, startX });

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop_front();

        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < plan.size() && 0 <= tx && tx < plan[0].size() && plan[ty][tx] != '#') {
                if (plan[ty][tx] == '.' && dist[ty][tx] > dist[y][x] + 1) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push_back({ ty, tx });
                } else if (plan[ty][tx] != '.' && dist[ty][tx] > dist[y][x]) {
                    dist[ty][tx] = dist[y][x];
                    q.push_front({ ty, tx });
                }
            }
        }
    }

    return dist;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int height, width;
    cin >> height >> width;

    vector<string> plan(height);
    vector<pair<int, int>> starts(3);
    for (int y = 0; y < height; y++) {
        cin >> plan[y];

        for (int x = 0; x < width; x++)
            if (isdigit(plan[y][x]))
                starts[plan[y][x] - '1'] = { y, x };
    }

    vector<vector<vector<int>>> dists;
    for (auto &[startY, startX] : starts)
        dists.push_back(bfs(plan, startY, startX));

    int res = 1e8;
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            if (plan[y][x] != '#')
                res = min(res, dists[0][y][x] + dists[1][y][x] + dists[2][y][x] - (plan[y][x] == '.' ? 2 : 0));

    cout << (res != 1e8 ? res : -1);
}
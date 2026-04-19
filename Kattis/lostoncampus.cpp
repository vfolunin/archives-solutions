#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

void bfs(vector<string> &plan, int startY, int startX) {
    vector<vector<int>> dist(plan.size(), vector<int>(plan[0].size(), 1e9));
    deque<pair<int, int>> q;

    dist[startY][startX] = 0;
    q.push_back({ startY, startX });


    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop_front();

        if (plan[y][x] == 'E') {
            cout << dist[y][x];
            return;
        }

        static vector<int> dy = { -1, 0, 1, 0 };
        static vector<int> dx = { 0, 1, 0, -1 };

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < plan.size() && 0 <= tx && tx < plan[0].size() && plan[ty][tx] != '#') {
                if (plan[ty][tx] == 'D' && dist[ty][tx] > dist[y][x] + 1) {
                    dist[ty][tx] = dist[y][x] + 1;
                    q.push_back({ ty, tx });
                } else if (plan[ty][tx] != 'D' && dist[ty][tx] > dist[y][x]) {
                    dist[ty][tx] = dist[y][x];
                    q.push_front({ ty, tx });
                }
            }
        }
    }

    cout << "NOT POSSIBLE";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int width, height;
    cin >> width >> height;

    vector<string> plan(height);
    int startY, startX;
    for (int y = 0; y < height; y++) {
        cin >> plan[y];

        for (int x = 0; x < width; x++) {
            if (plan[y][x] == '*') {
                startY = y;
                startX = x;
            }
        }
    }

    bfs(plan, startY, startX);
}
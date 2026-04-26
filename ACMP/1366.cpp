#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <tuple>
using namespace std;

void bfs(vector<string> &plan, int startY, int startX) {
    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    vector dist(plan.size(), vector(plan[0].size(), vector(dy.size(), 1e9)));
    queue<tuple<int, int, int>> q;

    for (int d = 0; d < dy.size(); d++) {
        dist[startY][startX][d] = 0;
        q.push({ startY, startX, d });
    }

    while (!q.empty()) {
        auto [y, x, d] = q.front();
        q.pop();

        if (plan[y][x] == 'F') {
            cout << dist[y][x][d];
            return;
        }

        for (int i = 0; i <= 1; i++) {
            int td = (d + i) % dy.size();
            int ty = y + dy[td];
            int tx = x + dx[td];
            if (0 <= ty && ty < plan.size() && 0 <= tx && tx < plan[0].size() &&
                plan[ty][tx] != 'X' && dist[ty][tx][td] > dist[y][x][d] + 1) {
                dist[ty][tx][td] = dist[y][x][d] + 1;
                q.push({ ty, tx, td });
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int height, width;
    cin >> height >> width;
    cin.ignore();
    
    vector<string> plan(height);
    int startY, startX;
    for (int y = 0; y < height; y++) {
        getline(cin, plan[y]);
        for (int x = 0; x < width; x++) {
            if (plan[y][x] == 'S') {
                startY = y;
                startX = x;
            }
        }
    }

    bfs(plan, startY, startX);
}
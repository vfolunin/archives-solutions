#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> bfs(int startY, int startX) {
    vector<vector<int>> dist(8, vector<int>(8, -1));
    queue<pair<int, int>> q;

    dist[startY][startX] = 0;
    q.push({ startY, startX });

    vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
    vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < 8 && 0 <= tx && tx < 8 && dist[ty][tx] == -1) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push({ ty, tx });
            }
        }
    }

    return dist;
}

int getProfit(int startY, int startX, int power, int limit) {
    vector<vector<int>> dist = bfs(startY, startX);
    long long sum = 0;
    for (int y = 0; y < dist.size(); y++)
        for (int x = 0; x < dist.size(); x++)
            if (power >= dist[y][x])
                sum += 1 << (power - dist[y][x]);
    return sum <= limit ? sum : 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int power, limit;
    cin >> power >> limit;

    long long resProfit = 0;
    vector<string> resCells;

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            int profit = getProfit(y, x, power, limit);
            string cell = string(1, x + 'a') + string(1, y + '1');

            if (profit) {
                if (resProfit < profit) {
                    resProfit = profit;
                    resCells = { cell };
                } else if (resProfit == profit) {
                    resCells.push_back(cell);
                }
            }
        }
    }

    cout << resProfit << "\n";
    for (string &cell : resCells)
        cout << cell << " ";
}
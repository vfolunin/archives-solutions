#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int getRes(vector<vector<int>> &population, vector<int> &positions) {
    vector<vector<int>> dist(5, vector<int>(5, 1e9));
    queue<int> q;

    for (int &position : positions) {
        dist[position / 5][position % 5] = 0;
        q.push(position / 5);
        q.push(position % 5);
    }

    while (!q.empty()) {
        int y = q.front();
        q.pop();
        int x = q.front();
        q.pop();

        static int dy[] = { -1, 0, 1, 0 };
        static int dx[] = { 0, 1, 0, -1 };

        for (int d = 0; d < 4; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (0 <= ty && ty < 5 && 0 <= tx && tx < 5 && dist[ty][tx] == 1e9) {
                dist[ty][tx] = dist[y][x] + 1;
                q.push(ty);
                q.push(tx);
            }
        }
    }

    int res = 0;
    for (int y = 0; y < 5; y++)
        for (int x = 0; x < 5; x++)
            res += dist[y][x] * population[y][x];
    return res;
}

void rec(vector<vector<int>> &population, vector<int> &positions, int i, int &bestRes, vector<int> &bestPositions) {
    if (i == 5) {
        int res = getRes(population, positions);
        if (bestRes > res) {
            bestRes = res;
            bestPositions = positions;
        }
        return;
    }
    for (positions[i] = (i ? positions[i - 1] + 1 : 0); positions[i] < 25; positions[i]++)
        rec(population, positions, i + 1, bestRes, bestPositions);
}

void solve() {
    int cellCount;
    cin >> cellCount;

    vector<vector<int>> population(5, vector<int>(5));
    for (int i = 0; i < cellCount; i++) {
        int row, col, pop;
        cin >> row >> col >> pop;
        population[row][col] = pop;
    }

    vector<int> positions(5), bestPositions(5);
    int bestRes = 1e9;
    rec(population, positions, 0, bestRes, bestPositions);

    for (int i = 0; i < 5; i++)
        cout << bestPositions[i] << (i < 4 ? ' ' : '\n');
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
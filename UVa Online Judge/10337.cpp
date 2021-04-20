#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int h = 10, w;
    cin >> w;
    w /= 100;

    vector<vector<int>> wind(h, vector<int>(w));
    for (int y = 9; y >= 0; y--)
        for (int x = 0; x < w; x++)
            cin >> wind[y][x];

    const int INF = 1e9;
    vector<vector<int>> cost(h, vector<int>(w + 1, INF));
    cost[0][0] = 0;
    
    for (int x = 0; x < w; x++) {
        for (int y = 9; y >= 0; y--) {
            if (cost[y][x] == INF)
                continue;
            if (y > 0)
                cost[y - 1][x + 1] = min(cost[y - 1][x + 1], cost[y][x] + 20 - wind[y][x]);
            cost[y][x + 1] = min(cost[y][x + 1], cost[y][x] + 30 - wind[y][x]);
            if (y < 9)
                cost[y + 1][x + 1] = min(cost[y + 1][x + 1], cost[y][x] + 60 - wind[y][x]);
        }
    }

    cout << cost[0][w] << "\n\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, roomsToClose;
    cin >> h >> roomsToClose;

    if (!h)
        return 0;

    vector<vector<vector<int>>> cost(h + 1, vector<vector<int>>(roomsToClose + 1, vector<int>(3, -1e9)));
    cost[0][0][0] = 0;

    for (int i = 1; i <= h; i++) {
        int a, b;
        cin >> a >> b;

        cost[i][0][0] = cost[i - 1][0][0] + a + b;

        for (int r = 1; r <= roomsToClose; r++) {
            cost[i][r][0] = max(cost[i - 1][r][0], max(cost[i - 1][r][1], cost[i - 1][r][2])) + a + b;
            cost[i][r][1] = max(cost[i - 1][r - 1][0], cost[i - 1][r - 1][1]) + a;
            cost[i][r][2] = max(cost[i - 1][r - 1][0], cost[i - 1][r - 1][2]) + b;
        }
    }

    cout << max(cost[h][roomsToClose][0], max(cost[h][roomsToClose][1], cost[h][roomsToClose][2])) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
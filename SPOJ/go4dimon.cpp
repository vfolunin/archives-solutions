#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;
    size = (size + 1) / 2;

    vector<vector<int>> price(size, vector<int>(size));
    for (int d = 0; d < size * 2 - 1; d++)
        for (int y = d, x = 0; y >= 0; y--, x++)
            if (0 <= y && y < size && 0 <= x && x < size)
                cin >> price[y][x];

    vector<vector<int>> cost(size, vector<int>(size, -1e9));
    cost[0][0] = price[0][0];
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (y)
                cost[y][x] = max(cost[y][x], cost[y - 1][x] + price[y][x]);
            if (x)
                cost[y][x] = max(cost[y][x], cost[y][x - 1] + price[y][x]);
        }
    }

    cout << cost.back().back() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
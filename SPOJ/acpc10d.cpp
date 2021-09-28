#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int h, w = 3;
    cin >> h;

    if (!h)
        return 0;

    vector<vector<int>> cost(h, vector<int>(w, 1e9));

    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> cost[y][x];

    cost[0][0] = 1e9;
    cost[0][2] += cost[0][1];

    for (int y = 1; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int add = cost[y - 1][x];

            if (x) {
                add = min(add, cost[y][x - 1]);
                add = min(add, cost[y - 1][x - 1]);
            }

            if (x + 1 < w)
                add = min(add, cost[y - 1][x + 1]);

            cost[y][x] += add;
        }
    }

    cout << test << ". " << cost[h - 1][1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<string> a(size);
    for (string &row : a)
        cin >> row;

    vector<vector<int>> cost(size, vector<int>(size, 1e9));
    cost[0][0] = a[0][0] - '0';
    vector<vector<pair<int, int>>> from(size, vector<pair<int, int>>(size, { -1, -1 }));

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (y && cost[y][x] > cost[y - 1][x] + a[y][x] - '0') {
                cost[y][x] = cost[y - 1][x] + a[y][x] - '0';
                from[y][x] = { y - 1, x };
            }
            if (x && cost[y][x] > cost[y][x - 1] + a[y][x] - '0') {
                cost[y][x] = cost[y][x - 1] + a[y][x] - '0';
                from[y][x] = { y, x - 1 };
            }
        }
    }

    vector<string> res(size, string(size, '-'));
    for (int y = size - 1, x = size - 1; y >= 0 && x >= 0; ) {
        res[y][x] = '#';
        auto &[py, px] = from[y][x];
        y = py;
        x = px;
    }

    for (string &row : res)
        cout << row << "\n";
}
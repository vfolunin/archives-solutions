#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size, targetY, targetX;
    if (!(cin >> size >> targetY >> targetX))
        return 0;
    targetY--;
    targetX--;

    vector<vector<int>> columns(1, vector<int>(size));
    for (int &val : columns[0])
        cin >> val;

    map<vector<int>, int> seen;
    seen[columns[0]] = 0;

    for (int x = 1; x <= targetX; x++) {
        columns.emplace_back(size);
        columns[x][0] = columns[x][size - 1] = 1;
        for (int y = 1; y + 1 < size; y++)
            columns[x][y] = (columns[x][y - 1] * columns[x - 1][y + 1] + 1) / columns[x - 1][y];

        if (seen.count(columns[x])) {
            int from = seen[columns[x]], cycleLength = x - from;
            targetX = (targetX - from) % cycleLength;
            break;
        }

        seen[columns[x]] = x;
    }

    cout << columns[targetX][targetY] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
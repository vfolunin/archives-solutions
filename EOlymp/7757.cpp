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

    vector<vector<int>> side(size, vector<int>(size));
    int maxSide = 0, maxSideCount = 0;

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            cin >> side[y][x];

            if (side[y][x] && y && x)
                side[y][x] += min({ side[y - 1][x - 1], side[y - 1][x], side[y][x - 1] });

            if (maxSide < side[y][x]) {
                maxSide = side[y][x];
                maxSideCount = 1;
            } else if (maxSide == side[y][x]) {
                maxSideCount++;
            }
        }
    }

    cout << maxSide * maxSideCount;
}
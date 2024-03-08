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

    int size, stepCount;
    cin >> size >> stepCount;

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cin >> a[y][x];

    vector<vector<int>> maxCost(size, vector<int>(size, -1e9));
    maxCost[0][0] = a[0][0];

    for (int i = 1; i < stepCount; i++) {
        vector<vector<int>> curCost(size, vector<int>(size, -1e9));

        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                static vector<int> dy = { -1, 0, 1, 0 };
                static vector<int> dx = { 0, 1, 0, -1 };

                for (int d = 0; d < dy.size(); d++) {
                    int ty = y + dy[d];
                    int tx = x + dx[d];

                    if (0 <= ty && ty < size && 0 <= tx && tx < size)
                        curCost[ty][tx] = max(curCost[ty][tx], maxCost[y][x] + a[ty][tx]);
                }
            }
        }

        maxCost.swap(curCost);
    }

    int res = 0;
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            res = max(res, maxCost[y][x]);

    cout << res;
}
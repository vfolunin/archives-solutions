#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const vector<int> DY = { -1, 0, 1, 0 };
const vector<int> DX = { 0, 1, 0, -1 };

bool isGood(set<pair<int, int>> &cells, int y, int x) {
    int neighborCount = 0;
    for (int d = 0; d < DY.size(); d++) {
        int ty = y + DY[d];
        int tx = x + DX[d];
        neighborCount += cells.count({ ty, tx });
    }
    return neighborCount == 3;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    set<pair<int, int>> cells, goodCells;

    for (int i = 0; i < size; i++) {
        int x, y;
        cin >> x >> y;

        cells.insert({ y, x });
        if (isGood(cells, y, x))
            goodCells.insert({ y, x });

        for (int d = 0; d < DY.size(); d++) {
            int ty = y + DY[d];
            int tx = x + DX[d];

            if (cells.count({ ty, tx })) {
                goodCells.erase({ ty, tx });
                if (isGood(cells, ty, tx))
                    goodCells.insert({ ty, tx });
            }
        }

        cout << goodCells.size() << "\n";
    }
}
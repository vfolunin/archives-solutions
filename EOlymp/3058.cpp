#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int squareCount(int diagonal) {
    return diagonal % 2 ? diagonal / 4 * 2 + 1 : (diagonal - 1) / 4 * 2 + 2;
}

long long bishopPlacements(int size, int bishopCount) {
    if (bishopCount > 2 * size - 1)
        return 0;
    if (!bishopCount)
        return 1;

    vector<vector<long long>> placements(size * 2, vector<long long>(bishopCount + 1));

    for (int diagonal = 0; diagonal < size * 2; diagonal++)
        placements[diagonal][0] = 1;
    placements[1][1] = 1;

    for (int diagonal = 2; diagonal < size * 2; diagonal++) {
        for (int bishops = 1; bishops <= bishopCount; bishops++) {
            placements[diagonal][bishops] += placements[diagonal - 2][bishops];
            placements[diagonal][bishops] += placements[diagonal - 2][bishops - 1] * (squareCount(diagonal) - bishops + 1);
        }
    }

    long long res = 0;
    for (int bishops = 0; bishops <= bishopCount; bishops++)
        res += placements[size * 2 - 1][bishops] * placements[size * 2 - 2][bishopCount - bishops];
    return res;
}

bool solve() {
    int size, bishopCount;
    cin >> size >> bishopCount;

    if (!size && !bishopCount)
        return 0;

    cout << bishopPlacements(size, bishopCount) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    while (solve());
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int pieceCount;
    cin >> pieceCount;

    if (!pieceCount)
        return 0;

    int bestPiece = -1;
    double bestSize = -1;
    for (int i = 0; i < pieceCount; i++) {
        double h, w;
        cin >> h >> w;

        vector<pair<int, int>> dimensions = { {1, 4}, {2, 2}, {4, 1} };
        for (auto &[rows, cols] : dimensions) {
            double size = min(h / rows, w / cols);
            if (size > bestSize) {
                bestPiece = i;
                bestSize = size;
            }
        }
    }

    cout << bestPiece + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
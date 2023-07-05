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

    int brickCount, w, h;
    cin >> brickCount >> w >> h;

    vector<vector<int>> levelSize(h, vector<int>(max(brickCount, w) + 1));
    levelSize[0][w] = w;

    for (int level = 0; level + 1 < h; level++) {
        for (int bricks = 0; bricks <= brickCount; bricks++) {
            if (levelSize[level][bricks]) {
                for (int delta : { -1, 1 }) {
                    int nextLevelSize = levelSize[level][bricks] + delta;
                    int nextBricks = bricks + nextLevelSize;
                    if (1 <= nextLevelSize && nextBricks <= brickCount)
                        levelSize[level + 1][nextBricks] = nextLevelSize;
                }
            }
        }
    }

    if (!levelSize[h - 1][brickCount]) {
        cout << 0;
        return 0;
    }

    vector<int> path;
    for (int level = h - 1; level >= 0; level--) {
        path.push_back(levelSize[level][brickCount]);
        brickCount -= levelSize[level][brickCount];
    }
    reverse(path.begin(), path.end());

    for (int value : path)
        cout << value << "\n";
}
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

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    int takenNeighborSum = 0;
    int maxFreeNeighborCount = 0;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int neighborCount = 0;

            static int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
            static int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

            for (int d = 0; d < 8; d++) {
                int ty = y + dy[d], tx = x + dx[d];
                neighborCount += 0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx] == 'o';
            }

            if (a[y][x] == 'o')
                takenNeighborSum += neighborCount;
            else
                maxFreeNeighborCount = max(maxFreeNeighborCount, neighborCount);
        }
    }

    cout << takenNeighborSum / 2 + maxFreeNeighborCount;
}
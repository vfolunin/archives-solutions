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

    int height, width, length;
    cin >> height >> width >> length;

    const int MOD = 1e9 + 7;
    vector<vector<int>> ways(height, vector<int>(width, 1));
    int totalWays = height * width;

    vector<int> dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
    vector<int> dx = { -1, 0, 1, 1, 1, 0, -1, -1 };

    for (int i = 1; i < length; i++) {
        vector<vector<int>> nextWays(height, vector<int>(width, totalWays));
        int nextTotalWays = 0;

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                nextWays[y][x] = (nextWays[y][x] - ways[y][x] + MOD) % MOD;

                for (int d = 0; d < dy.size(); d++) {
                    int ty = y + dy[d];
                    int tx = x + dx[d];

                    if (0 <= ty && ty < height && 0 <= tx && tx < width)
                        nextWays[y][x] = (nextWays[y][x] - ways[ty][tx] + MOD) % MOD;
                }

                nextTotalWays = (nextTotalWays + nextWays[y][x]) % MOD;
            }
        }

        ways.swap(nextWays);
        totalWays = nextTotalWays;
    }

    cout << totalWays;
}
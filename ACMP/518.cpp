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

    vector<string> a(size);
    for (string &row : a)
        cin >> row;

    vector<vector<vector<int>>> ways(stepCount + 1, vector<vector<int>>(size, vector<int>(size)));
    ways[0][0][0] = 1;

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    for (int steps = 0; steps < stepCount; steps++) {
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                if (!ways[steps][y][x])
                    continue;
                
                for (int d = 0; d < dy.size(); d++) {
                    int ty = y + dy[d];
                    int tx = x + dx[d];

                    if (0 <= ty && ty < size && 0 <= tx && tx < size && a[ty][tx] != '1')
                        ways[steps + 1][ty][tx] += ways[steps][y][x];
                }
            }
        }
    }

    cout << ways[stepCount][size - 1][size - 1];
}
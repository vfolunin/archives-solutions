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

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    vector<vector<int>> maxSum(h, vector<int>(w, -1e9));
    vector<vector<int>> ways(h, vector<int>(w, 1));
    for (int x = 0; x < w; x++)
        maxSum[0][x] = a[0][x];

    for (int y = 1; y < h; y++) {
        for (int x = 0; x < w; x++) {
            for (int dx : { -1, 0, 1 }) {
                int ty = y - 1;
                int tx = x + dx;

                if (0 <= tx && tx < w) {
                    if (maxSum[y][x] < maxSum[ty][tx] + a[y][x]) {
                        maxSum[y][x] = maxSum[ty][tx] + a[y][x];
                        ways[y][x] = ways[ty][tx];
                    } else if (maxSum[y][x] == maxSum[ty][tx] + a[y][x]) {
                        ways[y][x] += ways[ty][tx];
                    }
                }
            }
        }
    }

    int resSum = *max_element(maxSum.back().begin(), maxSum.back().end());
    int resWays = 0;
    for (int x = 0; x < w; x++)
        if (maxSum.back()[x] == resSum)
            resWays += ways.back()[x];

    cout << resSum << " " << resWays;
}
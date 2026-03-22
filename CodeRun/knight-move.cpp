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

    vector<vector<int>> ways(h, vector<int>(w));
    ways[0][0] = 1;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y >= 2 && x >= 1)
                ways[y][x] += ways[y - 2][x - 1];
            if (y >= 1 && x >= 2)
                ways[y][x] += ways[y - 1][x - 2];
        }
    }

    cout << ways[h - 1][w - 1];
}
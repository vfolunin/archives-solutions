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

    int h, w, badCount;
    cin >> h >> w >> badCount;

    vector<vector<int>> isBad(h, vector<int>(w));
    for (int i = 0; i < badCount; i++) {
        int y, x;
        cin >> y >> x;

        isBad[y - 1][x - 1] = 1;
    }

    vector<vector<int>> ways(h, vector<int>(w));
    ways[0][0] = !isBad[0][0];

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (!isBad[y][x]) {
                if (y)
                    ways[y][x] += ways[y - 1][x];
                if (x)
                    ways[y][x] += ways[y][x - 1];
            }
        }
    }

    cout << ways[h - 1][w - 1];
}
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
            int step;
            cin >> step;

            if (step) {
                if (y + step < h)
                    ways[y + step][x] += ways[y][x];
                if (x + step < w)
                    ways[y][x + step] += ways[y][x];
            }
        }
    }

    cout << ways[h - 1][w - 1];
}
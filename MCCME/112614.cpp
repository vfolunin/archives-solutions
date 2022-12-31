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

    vector<vector<long long>> ways(h, vector<long long>(w));
    ways[0][0] = 1;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            for (auto [dy, dx] : vector<pair<int, int>>{ { -2, -1 }, { -1, -2 } }) {
                int ty = y + dy;
                int tx = x + dx;

                if (0 <= ty && 0 <= tx)
                    ways[y][x] += ways[ty][tx];
            }
        }
    }

    cout << ways[h - 1][w - 1];
}
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

    const long long MOD = 1e9 + 7;
    vector<vector<int>> ways(h + 1, vector<int>(w + 1));
    ways[0][0] = 1;

    for (int y = 0; y <= h; y++) {
        for (int x = 0; x <= w; x++) {
            if (y < x || y * x % 2)
                continue;
            if (y)
                ways[y][x] = (ways[y][x] + ways[y - 1][x]) % MOD;
            if (x)
                ways[y][x] = (ways[y][x] + ways[y][x - 1]) % MOD;
        }
    }

    cout << ways[h][w];
}
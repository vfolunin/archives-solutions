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
    for (string &s : a)
        cin >> s;

    vector<vector<int>> ways(h, vector<int>(w));
    const int MOD = 1e9 + 7;
    ways[0][0] = a[0][0] != '#';

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] != '#') {
                if (y)
                    ways[y][x] = (ways[y][x] + ways[y - 1][x]) % MOD;
                if (x)
                    ways[y][x] = (ways[y][x] + ways[y][x - 1]) % MOD;
            }
        }
    }

    cout << ways.back().back();
}
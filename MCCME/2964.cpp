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
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int open;
            cin >> open;

            if (open) {
                if (y && x)
                    ways[y][x] = ways[y - 1][x] + ways[y][x - 1];
                else if (y)
                    ways[y][x] = ways[y - 1][x];
                else if (x)
                    ways[y][x] = ways[y][x - 1];
                else
                    ways[y][x] = 1;
            }
        }
    }

    if (ways[h - 1][w - 1])
        cout << ways[h - 1][w - 1];
    else
        cout << "Impossible";
}
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

    int y, x;
    cin >> x >> y;

    vector<vector<int>> ways(8, vector<int>(8));
    ways[y - 1][x - 1] = 1;

    for (y; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            if (x)
                ways[y][x] += ways[y - 1][x - 1];
            if (x < 7)
                ways[y][x] += ways[y - 1][x + 1];
        }
    }

    int res = 0;
    for (int count : ways[7])
        res += count;

    cout << res;
}
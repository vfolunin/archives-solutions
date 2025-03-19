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
    ways[0][0] = 1;
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            for (int ty = y + 1; ty < h; ty++)
                for (int tx = x + 1; tx < w; tx++)
                    if (a[y][x] != a[ty][tx])
                        ways[ty][tx] += ways[y][x];

    cout << ways[h - 1][w - 1];
}
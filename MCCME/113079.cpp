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

    vector<vector<int>> res(h, vector<int>(w, 2));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            for (int i = 1; i <= y; i++)
                if (res[y - i][x] == 2)
                    res[y][x] = 1;

            for (int i = 1; i <= x; i++)
                if (res[y][x - i] == 2)
                    res[y][x] = 1;

            for (int i = 1; i <= y && i <= x; i++)
                if (res[y - i][x - i] == 2)
                    res[y][x] = 1;
        }
    }

    cout << res[h - 1][w - 1];
}
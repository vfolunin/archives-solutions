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

    int height, width, partCount;
    cin >> height >> width >> partCount;

    set<pair<int, int>> parts;
    for (int i = 0; i < partCount; i++) {
        int height, width;
        cin >> height >> width;

        parts.insert({ height, width });
    }

    vector<vector<int>> res(height + 1, vector<int>(width + 1));
    for (int h = 1; h <= height; h++) {
        for (int w = 1; w <= width; w++) {
            if (parts.count({ h, w }))
                res[h][w] = 1;

            for (int h1 = 1, h2 = h - 1; h1 <= h2; h1++, h2--)
                res[h][w] = max(res[h][w], res[h1][w] + res[h2][w]);
            for (int w1 = 1, w2 = w - 1; w1 <= w2; w1++, w2--)
                res[h][w] = max(res[h][w], res[h][w1] + res[h][w2]);
        }
    }

    cout << res[height][width];
}
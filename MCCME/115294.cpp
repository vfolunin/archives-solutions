#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <tuple>
using namespace std;

tuple<int, int, int, int> dfs(vector<string> &a, int y, int x) {
    a[y][x] = '.';
    int minY = y, minX = x, maxY = y, maxX = x;

    static vector<int> dy = { -1, -1, -1, 0, 1, 1, 1, 0 };
    static vector<int> dx = { -1, 0, 1, 1, 1, 0, -1, -1 };
    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a[0].size() && a[ty][tx] == '#') {
            auto [toMinY, toMinX, toMaxY, toMaxX] = dfs(a, ty, tx);
            minY = min(minY, toMinY);
            minX = min(minX, toMinX);
            maxY = max(maxY, toMaxY);
            maxX = max(maxX, toMaxX);
        }
    }

    return { minY, minX, maxY, maxX };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> a(10);
    for (string &s : a)
        cin >> s;

    vector<int> count(4);
    for (int y = 0; y < a.size(); y++) {
        for (int x = 0; x < a[0].size(); x++) {
            if (a[y][x] == '#') {
                auto [minY, minX, maxY, maxX] = dfs(a, y, x);
                int h = maxY - minY + 1;
                int w = maxX - minX + 1;
                if (h > 1 && w > 1 || h * w > 4) {
                    cout << "NO";
                    return 0;
                }
                count[h * w - 1]++;
            }
        }
    }

    cout << (count == vector<int>{ 4, 3, 2, 1 } ? "YES" : "NO");
}
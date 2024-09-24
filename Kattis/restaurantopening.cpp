#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getCost(vector<vector<int>> &a, int ty, int tx) {
    int res = 0;
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a[0].size(); x++)
            res += a[y][x] * (abs(y - ty) + abs(x - tx));
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    int res = getCost(a, 0, 0);
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            res = min(res, getCost(a, y, x));

    cout << res;
}
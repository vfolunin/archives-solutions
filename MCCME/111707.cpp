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

    int h, w, rectangleCount;
    cin >> h >> w >> rectangleCount;

    vector<vector<int>> a(h, vector<int>(w, 1));
    for (int i = 0; i < rectangleCount; i++) {
        int yl, xl, yr, xr;
        cin >> yl >> xl >> yr >> xr;
        
        for (int y = yl; y < yr; y++)
            for (int x = xl; x < xr; x++)
                a[y][x] = 0;
    }

    int res = 0;
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            res += a[y][x];

    cout << res;
}
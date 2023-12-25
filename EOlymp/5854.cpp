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
 
    vector<vector<int>> a(h, vector<int>(w));
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cin >> a[y][x];

    vector<vector<int>> maxCost(h, vector<int>(w, -1e9));
    maxCost[0] = a[0];

    for (int y = 1; y < h; y++)
        for (int x = 0; x < w; x++)
            for (int px : { x - 1, x, x + 1 })
                if (0 <= px && px < w)
                    maxCost[y][x] = max(maxCost[y][x], maxCost[y - 1][px] + a[y][x]);
            

    cout << *max_element(maxCost.back().begin(), maxCost.back().end());
}
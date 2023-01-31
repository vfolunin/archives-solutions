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
    vector<int> rowMin(h, 1e9), colMax(w, -1e9);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            rowMin[y] = min(rowMin[y], a[y][x]);
            colMax[x] = max(colMax[x], a[y][x]);
        }
    }

    bool found = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] == rowMin[y] && a[y][x] == colMax[x]) {
                found = 1;
                cout << y + 1 << " " << x + 1 << "\n";
            }
        }
    }

    if (!found)
        cout << 0;
}
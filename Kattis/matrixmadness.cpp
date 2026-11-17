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

    for (int y1 = 0; y1 < h; y1++) {
        for (int x1 = 0; x1 < w; x1++) {
            for (int y2 = 0; y2 < h; y2++) {
                for (int x2 = 0; x2 < w; x2++) {
                    if ((y1 != y2 || x1 != x2) && a[y1][x1] == a[y2][x2] &&
                        abs(y1 - y2) + abs(x1 - x2) <= a[y1][x1]) {
                        cout << "INVALID";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "VALID";
}
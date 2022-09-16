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
    int resY = 0, resX = 0;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            if (a[resY][resX] < a[y][x]) {
                resY = y;
                resX = x;
            }
        }
    }

    cout << a[resY][resX] << "\n" << resY << " " << resX;
}
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
    int maxY = 0, maxX = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> a[y][x];
            if (a[maxY][maxX] < a[y][x]) {
                maxY = y;
                maxX = x;
            }
        }
    }

    int minY = 0;
    for (int y = 1; y < h; y++)
        if (a[minY][maxX] > a[y][maxX])
            minY = y;

    int minX = 0;
    for (int x = 1; x < w; x++)
        if (a[maxY][minX] > a[maxY][x])
            minX = x;

    cout << a[minY][minX];
}
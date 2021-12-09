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

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    int coastCount = 0;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] == '.')
                continue;

            static int dy[] = { -1, 0, 1, 0 };
            static int dx[] = { 0, 1, 0, -1 };
            for (int d = 0; d < 4; d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];

                if (ty < 0 || ty >= h || tx < 0 || tx >= w || a[ty][tx] == '.') {
                    coastCount++;
                    break;
                }
            }
        }
    }

    cout << coastCount << "\n";
}
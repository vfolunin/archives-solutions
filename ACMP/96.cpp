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

    int h, w, finishY, finishX;
    cin >> h >> w >> finishY >> finishX;
    finishY--;
    finishX--;

    vector<vector<int>> a(h, vector<int>(w));
    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };
    int y = 0, x = 0, d = 1, res = 0;

    while (1) {
        a[y][x] = 1;
        res++;

        if (y == finishY && x == finishX)
            break;

        while (1) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < h && 0 <= tx && tx < w && !a[ty][tx]) {
                y = ty;
                x = tx;
                break;
            }

            d = (d + 1) % dy.size();
        }
    }

    cout << res;
}
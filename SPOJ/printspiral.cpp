#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    for (int y = 0, x = 0, d = 1, value = 1; value <= h * w; value++) {
        a[y][x] = value;
        for (int i = 0; i < dy.size(); i++) {
            int ty = y + dy[d];
            int tx = x + dx[d];
            if (0 <= ty && ty < h && 0 <= tx && tx < w && !a[ty][tx]) {
                y = ty;
                x = tx;
                break;
            } else {
                d = (d + 1) % dy.size();
            }
        }
    }

    cout << "Case " << test << ":\n";
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            cout << setw(h * w > 9 ? 2 : 1) << setfill('0') << a[y][x] << (x + 1 < w ? " " : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}
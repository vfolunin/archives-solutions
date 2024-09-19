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

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            bool ok = 1;

            for (int d = 0; d < dy.size() && ok; d++) {
                int ty = y + dy[d];
                int tx = x + dx[d];
                ok &= 0 <= ty && ty < h && 0 <= tx && tx < w && a[y][x] < a[ty][tx];
            }

            if (ok) {
                cout << "Jebb";
                return 0;
            }
        }
    }

    cout << "Neibb";
}
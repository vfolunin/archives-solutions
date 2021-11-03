#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int h, w;
    if (!(cin >> h >> w))
        return 0;

    vector<vector<int>> a(h, vector<int>(w));
    for (vector<int> &row : a)
        for (int &x : row)
            cin >> x;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x]) {
                cout << 9;
                continue;
            }

            static int dy[] = { -1, 0, 1, 0 };
            static int dx[] = { 0, 1, 0, -1 };
            
            int k = 0;
            for (int d = 0; d < 4; d++) {
                int ty = y + dy[d], tx = x + dx[d];
                k += 0 <= ty && ty < h && 0 <= tx && tx < w && a[ty][tx];
            }
            cout << k;
        }
        cout << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
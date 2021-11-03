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
    for (vector<int> &row : a)
        for (int &x : row)
            cin >> x;

    for (int y = 1; y + 1 < h; y++) {
        for (int x = 1; x + 1 < w; x++) {
            if (a[y][x] == 42) {
                static int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
                static int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
                bool ok = 1;
                for (int d = 0; ok && d < 8; d++)
                    ok &= a[y + dy[d]][x + dx[d]] == 7;
                if (ok) {
                    cout << y + 1 << " " << x + 1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "0 0\n";
}
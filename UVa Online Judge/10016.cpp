#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cin >> a[y][x];

    int ringCount = (size + 1) / 2;
    for (int r = 0; r < ringCount; r++) {
        int flipCount;
        cin >> flipCount;

        for (int j = 0; j < flipCount; j++) {
            int type;
            cin >> type;

            if (type == 1) {
                for (int x = r; x < size - r; x++)
                    swap(a[r][x], a[size - 1 - r][x]);
                for (int y = r + 1; y < size - 1 - y; y++) {
                    swap(a[y][r], a[size - 1 - y][r]);
                    swap(a[y][size - 1 - r], a[size - 1 - y][size - 1 - r]);
                }
            } else if (type == 2) {
                for (int y = r; y < size - r; y++)
                    swap(a[y][r], a[y][size - 1 - r]);
                for (int x = r + 1; x < size - 1 - x; x++) {
                    swap(a[r][x], a[r][size - 1 - x]);
                    swap(a[size - 1 - r][x], a[size - 1 - r][size - 1 - x]);
                }
            } else if (type == 3) {
                for (int x = r; x < size - r; x++)
                    swap(a[r][x], a[x][r]);
                for (int y = r + 1; y < size - r; y++)
                    swap(a[y][size - 1 - r], a[size - 1 - r][y]);
            } else {
                for (int x = r; x < size - r; x++)
                    swap(a[r][x], a[size - 1 - x][size - 1 - r]);
                for (int y = r + 1; y < size - r; y++)
                    swap(a[y][r], a[size - 1 - r][size - 1 - y]);
            }
        }
    }

    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cout << a[y][x] << (x + 1 < size ? " " : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
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

    for (int y = 0; y + 3 <= h; y++) {
        for (int x = 0; x < w; x++) {
            if (!a[y][x] && !a[y + 1][x] && !a[y + 2][x]) {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
}
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

    int x1, x2;
    cin >> x1 >> x2;

    for (int y = 0; y < h; y++)
        swap(a[y][x1], a[y][x2]);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}
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

    int cellCount;
    cin >> cellCount;

    int sum = 0;
    for (int i = 0; i < cellCount; i++) {
        int y, x;
        cin >> y >> x;
        y--;
        x--;

        sum += a[y][x];
        a[y][x] = 0;
    }

    cout << sum;
}
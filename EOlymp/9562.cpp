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

    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--;
    x1--;

    int sum = 0;
    for (int y = y1; y < y2; y++)
        for (int x = x1; x < x2; x++)
            sum += a[y][x];

    cout << sum;
}
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

    int h, w, centerY, centerX, radius;
    cin >> h >> w >> centerY >> centerX >> radius;

    int res = 0;
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            res += (y - centerY) * (y - centerY) + (x - centerX) * (x - centerX) <= radius * radius;

    cout << res;
}
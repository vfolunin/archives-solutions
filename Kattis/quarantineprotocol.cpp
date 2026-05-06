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

    int height, width;
    cin >> height >> width;

    vector<string> plan(height, string(width, ' '));
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            cin >> plan[y][x];

    int res = height * width;
    for (int x = 0; x < width; x++) {
        int py = -1, hasX = 0;
        for (int y = 0; y < height; y++) {
            if (plan[y][x] == 'X') {
                hasX = 1;
            } else if (plan[y][x] == '#') {
                if (hasX)
                    res -= y - py - 1;
                py = y;
                hasX = 0;
            }
        }
        if (hasX)
            res -= height - py - 1;
    }

    cout << res;
}
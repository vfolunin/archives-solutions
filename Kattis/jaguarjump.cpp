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

    int w, h, limit;
    cin >> w >> h >> limit;

    int y1, x1, y2, x2;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            char c;
            cin >> c;

            if (c == 'J') {
                y1 = y;
                x1 = x;
            } else if (c == '@') {
                y2 = y;
                x2 = x;
            }
        }
    }

    if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= limit * limit)
        cout << "the guide is right";
    else
        cout << "no jumpscares here";
}
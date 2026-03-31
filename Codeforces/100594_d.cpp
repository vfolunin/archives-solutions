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

    int h, w, y1, x1, y2, x2;
    cin >> h >> w >> y1 >> x1 >> y2 >> x2;

    int dy = abs(y1 - y2);
    dy = min(dy, h - dy);
    int dx = abs(x1 - x2);
    dx = min(dx, w - dx);

    cout << (dy + dx + 1) / 2;
}
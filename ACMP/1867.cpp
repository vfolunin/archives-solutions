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

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    string moves;
    cin >> moves >> moves;

    vector<int> dy = { -1, 0, 1, 0 };
    vector<int> dx = { 0, 1, 0, -1 };
    string dc = "WDSA";

    int minY = 0, maxY = h - 1, minX = 0, maxX = w - 1;
    for (char move : moves) {
        int d = dc.find(move);
        y += dy[d];
        x += dx[d];

        minY = min(minY, y);
        maxY = max(maxY, y);
        minX = min(minX, x);
        maxX = max(maxX, x);
    }

    cout << (maxY - minY + 1LL) * (maxX - minX + 1LL);
}
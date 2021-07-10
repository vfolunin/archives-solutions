#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getCoords(int n) {
    if (!n)
        return { 0, 0, 0 };
    n--;

    int ring = 1;
    while (n >= ring * 6) {
        n -= ring * 6;
        ring++;
    }

    int x = ring - 1, y = -ring, z = 1;

    int dx[] = { -1, -1, 0, 1, 1, 0 };
    int dy[] = { 0, 1, 1, 0, -1, -1 };
    int dz[] = { 1, 0, -1, -1, 0, 1 };

    for (int d = 0; d < 6; d++) {
        for (int i = 0; i < (d ? ring : ring - 1) && n; i++) {
            x += dx[d];
            y += dy[d];
            z += dz[d];
            n--;
        }
    }
    return { x, y, z };
}

int getDist(vector<int> &a, vector<int> &b) {
    int d = 0;
    for (int i = 0; i < 3; i++)
        d = max(d, abs(a[i] - b[i]));
    return d;
}

bool solve() {
    int a, b;
    if (!(cin >> a >> b) || !a && !b)
        return 0;

    vector<int> coordsA = getCoords(a - 1);
    vector<int> coordsB = getCoords(b - 1);
    int dist = getDist(coordsA, coordsB);

    cout << "The distance between cells " << a << " and " << b << " is " << dist << ".\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
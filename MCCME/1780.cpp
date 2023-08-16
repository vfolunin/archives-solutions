#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Triangle {
    int x, y, side;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int triangleCount;
    cin >> triangleCount;

    vector<Triangle> triangles(triangleCount);
    int maxX = -1e9, maxY = -1e9;

    for (auto &[x, y, side] : triangles) {
        cin >> x >> y >> side;
        maxX = max(maxX, x);
        maxY = max(maxY, y);
    }

    int resSide = 1e9;
    for (auto &[x, y, side] : triangles)
        resSide = min(resSide, side - (maxX - x) - (maxY - y));
    resSide = max(resSide, 0);

    cout << fixed << resSide * resSide / 2.0;
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> getCoords(int n) {
    if (!n)
        return { 0, 0 };
    n--;

    int ring = 1;
    while (n >= ring * 4) {
        n -= ring * 4;
        ring++;
    }

    int x = 1 - ring, y = 1;
    static int dx[] = { 1, 1, -1, -1 };
    static int dy[] = { 1, -1, -1, 1 };

    for (int d = 0; n && d < 4; d++) {
        int k = min(n, d ? ring : ring - 1);
        x += dx[d] * k;
        y += dy[d] * k;
        n -= k;
    }

    return { x, y };
}

bool solve() {
    int a, b;
    cin >> a >> b;

    if (a == -1 && b == -1)
        return 0;

    auto [xa, ya] = getCoords(a);
    auto [xb, yb] = getCoords(b);

    cout.precision(2);
    cout << fixed << hypot(xa - xb, ya - yb) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
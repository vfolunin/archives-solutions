#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> read() {
    char x, y;
    cin >> x >> y;
    return { y - '1', x - 'A' };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    auto [qy, qx] = read();
    auto [ry, rx] = read();
    auto [ny, nx] = read();

    int res = 0;
    for (int y = 0; y < 8; y++)
        for (int x = 0; x < 8; x++)
            res += (y != qy || x != qx) && (y != ry || x != rx) && (y != ny || x != nx) &&
                   (y == qy || x == qx || y + x == qy + qx || y - x == qy - qx ||
                    y == ry || x == rx || abs(y - ny) * abs(x - nx) == 2);

    cout << res;
}
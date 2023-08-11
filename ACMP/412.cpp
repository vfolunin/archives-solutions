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

bool isBetween(int l, int x, int r) {
    return l < x && x < r || l > x && x > r;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    auto [k1y, k1x] = read();
    auto [qy, qx] = read();
    auto [k2y, k2x] = read();

    if (qy == k2y)
        cout << (qy == k1y && isBetween(qx, k1x, k2x) ? "NO" : "YES");
    else if (qx == k2x)
        cout << (qx == k1x && isBetween(qy, k1y, k2y) ? "NO" : "YES");
    else if (qy + qx == k2y + k2x)
        cout << (qy + qx == k1y + k1x && isBetween(qy, k1y, k2y) ? "NO" : "YES");
    else if (qy - qx == k2y - k2x)
        cout << (qy - qx == k1y - k1x && isBetween(qy, k1y, k2y) ? "NO" : "YES");
    else
        cout << "NO";
}
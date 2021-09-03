#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> getCoords(int n) {
    int row = ceil(sqrt(n));
    int col = n - (row - 1) * (row - 1);
    return { row, col };
}

int triangleGridDist(int ay, int ax, int by, int bx) {
    return abs(ay - by) + abs((ay - ax / 2) - (by - bx / 2)) + abs((ax + 1) / 2 - (bx + 1) / 2);
}

void solve(int test) {
    int a, b;
    cin >> a >> b;

    auto [ay, ax] = getCoords(a);
    auto [by, bx] = getCoords(b);

    if (test)
        cout << "\n";
    cout << triangleGridDist(ay, ax, by, bx) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}
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

    long long h, w, y, x;
    cin >> h >> w >> y >> x;
    y--;
    x--;

    cout << (h + 1) * h / 2 * (w + 1) * w / 2 - (y + 1) * (x + 1) * (h - y) * (w - x);
}
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

    int x, y, xl, yl, xr, yr;
    cin >> x >> y >> xl >> yl >> xr >> yr;

    if (xl > xr)
        swap(xl, xr);
    if (yl > yr)
        swap(yl, yr);

    cout << (xl <= x && x <= xr && yl <= y && y <= yr);
}
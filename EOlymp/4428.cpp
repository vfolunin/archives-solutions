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

    int size;
    cin >> size;

    int xl = -1e9, xr = 1e9, yl = -1e9, yr = 1e9;
    for (int i = 0; i < size; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        xl = max(xl, x1);
        yl = max(yl, y1);
        xr = min(xr, x2);
        yr = min(yr, y2);
    }

    if (xl <= xr && yl <= yr)
        cout << xl << " " << yl << " " << xr << " " << yr;
    else
        cout << -1;
}
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

    int w, h, xa, ya, xb, yb;
    cin >> w >> h >> xa >> ya >> xb >> yb;

    int res = 0;

    if (xa != xb) {
        if (xa > xb) {
            swap(xa, xb);
            swap(ya, yb);
        }
        res = max({ res, h * xa, h * (w - xa), h * (xb - 1), h * (w - xb + 1) });
    }

    if (ya != yb) {
        if (ya > yb) {
            swap(xa, xb);
            swap(ya, yb);
        }
        res = max({ res, w * ya, w * (h - ya), w * (yb - 1), w * (h - yb + 1) });
    }

    cout << res;
}
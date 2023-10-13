#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> ask(int y, int x) {
    cout << y << " " << x << endl;
    int dy, dx;
    cin >> dy >> dx;
    return { dy, dx };
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int yl = -2e6, yr = 2e6;
    int xl = -2e6, xr = 2e6;
    while (1) {
        int y = (yl + yr) / 2;
        int x = (xl + xr) / 2;

        auto [dy, dx] = ask(y, x);
        if (!dy && !dx)
            break;

        if (dy > 0) {
            yl = y + 1;
            yr++;
        }
        if (dy < 0) {
            yl--;
            yr = y - 1;
        }
        if (dx > 0) {
            xl = x + 1;
            xr++;
        }
        if (dx < 0) {
            xl--;
            xr = x - 1;
        }
    }
}
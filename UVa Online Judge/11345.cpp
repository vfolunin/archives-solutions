#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int rectCount;
    cin >> rectCount;

    int xl = -1e9, yl = -1e9, xr = 1e9, yr = 1e9;
    for (int i = 0; i < rectCount; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        xl = max(xl, x1);
        yl = max(yl, y1);
        xr = min(xr, x2);
        yr = min(yr, y2);
    }

    cout << "Case " << test << ": " << max(yr - yl, 0) * max(xr - xl, 0) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
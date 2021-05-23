#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int dx = x2 - x1, dy = y2 - y1;
    int x3 = -dy, y3 = dx;
    if (x3 < 0 || y3 < 0) {
        x3 = -x3;
        y3 = -y3;
    }

    cout << "Case " << test << ": ";
    if (x3 >= 0 && y3 >= 0)
        cout << "0 0 " << x3 << " " << y3 << "\n";
    else if (x3 < 0)
        cout << -x3 << " 0 0 " << y3 << "\n";
    else if (y3 < 0)
        cout << "0 " << -y3 << " " << x3 << " 0\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n, x0, y0;
    if (!(cin >> n >> x0 >> y0))
        return 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (x == x0 || y == y0)
            cout << "divisa\n";
        else if (x > x0 && y > y0)
            cout << "NE\n";
        else if (x > x0 && y < y0)
            cout << "SE\n";
        else if (x < x0 && y > y0)
            cout << "NO\n";
        else
            cout << "SO\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
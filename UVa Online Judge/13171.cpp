#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int m, y, c;
    string colors;
    cin >> m >> y >> c >> colors;

    for (char color : colors) {
        if (color == 'M' || color == 'R' || color == 'V' || color == 'B')
            m--;
        if (color == 'Y' || color == 'R' || color == 'G' || color == 'B')
            y--;
        if (color == 'C' || color == 'G' || color == 'V' || color == 'B')
            c--;
    }

    if (m >= 0 && y >= 0 && c >= 0)
        cout << "YES " << m << " " << y << " " << c << "\n";
    else
        cout << "NO\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
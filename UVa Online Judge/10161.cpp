#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    int row = sqrt(n - 1) + 1;

    int x, y;
    if (row % 2) {
        x = min(row * row - n + 1, row);
        y = min(n - (row - 1) * (row - 1), row);
    } else {
        x = min(n - (row - 1) * (row - 1), row);
        y = min(row * row - n + 1, row);
    }

    cout << x << " " << y << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
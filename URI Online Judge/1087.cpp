#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;

    if (!y1)
        return 0;

    if (y1 == y2 && x1 == x2)
        cout << "0\n";
    else if (y1 == y2 || x1 == x2 || y1 + x1 == y2 + x2 || y1 - x1 == y2 - x2)
        cout << "1\n";
    else
        cout << "2\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
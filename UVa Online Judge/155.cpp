#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int count(int size, int cx, int cy, int x, int y) {
    int res = cx - size <= x && x <= cx + size &&
              cy - size <= y && y <= cy + size;
    if (size > 1) {
        res += count(size / 2, cx - size, cy - size, x, y);
        res += count(size / 2, cx - size, cy + size, x, y);
        res += count(size / 2, cx + size, cy - size, x, y);
        res += count(size / 2, cx + size, cy + size, x, y);
    }
    return res;
}

bool solve() {
    int size, x, y;
    cin >> size >> x >> y;

    if (!size)
        return 0;

    cout << setw(3) << count(size, 1024, 1024, x, y) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
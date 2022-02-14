#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long size, x, y, dx, dy;
    cin >> size >> x >> y >> dx >> dy;

    if (!size)
        return 0;

    for (int i = 0; i < 10000; i++) {
        if (x % size && y % size && (x / size + y / size) % 2) {
            cout << "After " << i << " jumps the flea lands at (" << x << ", " << y << ").\n";
            return 1;
        }
        x += dx;
        y += dy;
    }

    cout << "The flea cannot escape from black squares.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
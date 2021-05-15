#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long r;
    if (!(cin >> r))
        return 0;

    long long res = 0;
    for (long long x = 0, y = r; x <= r; x++) {
        while (x * x + y * y > r * r)
            y--;
        res += y;
    }

    cout << r << "\n";
    cout << 4 * res + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
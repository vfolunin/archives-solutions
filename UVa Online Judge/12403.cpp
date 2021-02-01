#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int distCW(int a, int b) {
    return (a <= b ? b - a : b + 40 - a) * 9;
}

int distCCW(int a, int b) {
    return (a >= b ? a - b : a + 40 - b) * 9;
}

bool solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (!a && !b && !c && !d)
        return 0;

    cout << 360 * 3 + distCCW(a, b) + distCW(b, c) + distCCW(c, d) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
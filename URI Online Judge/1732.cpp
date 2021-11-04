#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;
    n--;

    if (!n) {
        cout << "0 0\n";
        return 1;
    }
    n--;

    int circleSize = 1;
    while (n >= circleSize * 6) {
        n -= circleSize * 6;
        circleSize++;
    }

    int a = circleSize - 1, b = 1, d = 0;
    int da[] = { -1, -1, 0, 1, 1, 0 };
    int db[] = { 1, 0, -1, -1, 0, 1 };
    while (n >= circleSize) {
        n -= circleSize;
        a += da[d] * (circleSize - 1);
        b += db[d] * (circleSize - 1);
        d = (d + 1) % 6;
        a += da[d];
        b += db[d];
    }
    a += da[d] * n;
    b += db[d] * n;

    cout << a << " " << b << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
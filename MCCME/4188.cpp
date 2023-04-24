#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcdex(long long a, long long b, long long &x, long long &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1, d = gcdex(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return d;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, b, c;
    cin >> a >> b >> c;

    long long x, y, g = gcdex(a, b, x, y);

    if (c % g) {
        cout << "Impossible";
        return 0;
    }

    long long d = c / g, dx = b / g, dy = a / g;
    x *= d;
    y *= d;

    if (x > 0) {
        long long k = x / dx;
        x -= k * dx;
        y += k * dy;
    } else {
        long long k = (-x + dx - 1) / dx;
        x += k * dx;
        y -= k * dy;
    }

    cout << x << " " << y;
}
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

void solve() {
    long long a, b;
    cin >> a >> b;

    long long x, y, d = gcdex(a, b, x, y);

    if (d > 1) {
        cout << "No Solution\n";
        return;
    }

    if (x >= 0) {
        long long k = x / (b / d);
        x -= b / d * k;
        y += a / d * k;
    } else {
        long long k = (-x + b / d - 1) / (b / d);
        x += b / d * k;
        y -= a / d * k;
    }

    cout << x << " " << y << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
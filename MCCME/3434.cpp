#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b, x, y;
    cin >> a >> b >> x >> y;

    int d = gcd(x, y);
    x /= d;
    y /= d;

    int l = 0, r = a / x + 1;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (m * x <= a && m * y <= b)
            l = m;
        else
            r = m;
    }

    cout << l * x << " " << l * y;
}
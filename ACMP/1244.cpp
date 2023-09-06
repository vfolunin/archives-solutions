#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long ra1, ra2, rb1, rb2, a, b, c, d, x, y;
    cin >> ra1 >> ra2 >> rb1 >> rb2 >> a >> b >> c >> d >> x >> y;

    long long res = 0;
    if (x >= 0 && y >= 0)
        res = max(res, a);
    if (x <= 0 && y >= 0)
        res = max(res, b);
    if (x <= 0 && y <= 0)
        res = max(res, c);
    if (x >= 0 && y <= 0)
        res = max(res, d);

    long long r = x * x + y * y;
    if (ra1 * ra1 <= r && r <= ra2 * ra2)
        res *= 2;
    if (rb1 * rb1 <= r && r <= rb2 * rb2)
        res *= 3;
    if (ra2 * ra2 < r)
        res = 0;

    cout << res;
}
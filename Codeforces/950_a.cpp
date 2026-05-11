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

    int l, r, a;
    cin >> l >> r >> a;

    int res = 0;

    int delta = min(l, r);
    l -= delta;
    r -= delta;
    res += 2 * delta;

    delta = min(l, a);
    l -= delta;
    a -= delta;
    res += 2 * delta;

    delta = min(r, a);
    r -= delta;
    a -= delta;
    res += 2 * delta;

    res += a / 2 * 2;

    cout << res;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(int a, int b, int c, int n) {
    if (a < 2 * n || b < n)
        return 0;

    a -= 2 * n;
    b -= n;
    return a + b >= c;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b, c;
    cin >> a >> b >> c;

    int l = 0, r = 1;
    while (can(a, b, c, r))
        r *= 2;

    while (l + 1 < r) {
        int m = l + (r - l) / 2;
        if (can(a, b, c, m))
            l = m;
        else
            r = m;
    }

    cout << l;
}
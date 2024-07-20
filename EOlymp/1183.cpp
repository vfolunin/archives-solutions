#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int rec(int a, int b) {
    if (!a || !b)
        return 0;

    if (a > b)
        return rec(a - b, 2 * b) + 1;
    else
        return rec(2 * a, b - a) + 1;
}

bool solve() {
    int a, b;
    if (!(cin >> a >> b))
        return 0;

    int n = (a + b) / gcd(a, b);

    cout << (n & (n - 1) ? -1 : rec(a, b)) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
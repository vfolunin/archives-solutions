#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n, a, b, w;
    if (!(cin >> n >> a >> b >> w))
        return 0;

    cout.precision(4);
    cout << fixed << n * hypot(a, b) * w / 1e4 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
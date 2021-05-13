#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double h, w;
    if (!(cin >> h >> w))
        return 0;

    cout.precision(3);
    cout << fixed << (-sqrt(h * h + w * w - h * w) + h + w) / 6 << " ";
    cout << 0.0 << " ";
    cout << min(h, w) / 2 + 1e-9 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
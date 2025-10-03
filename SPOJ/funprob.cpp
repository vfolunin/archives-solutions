#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double k10, k5;
    cin >> k10 >> k5;

    if (!k10 && !k5)
        return 0;

    cout << fixed << (k5 - k10 + 1) / (k5 + 1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
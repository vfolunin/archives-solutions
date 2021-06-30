#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double r;
    if (!(cin >> r))
        return 0;

    cout.precision(5);
    cout << fixed << 7.0225095034304 * r << " ";
    cout << fixed << 7.5191308906316 * r << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
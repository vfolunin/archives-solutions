#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    double res = 1;
    for (int i = 1; i < n; i++)
        res *= 1 - i / 365.0;

    cout.precision(8);
    cout << fixed << 100 * (1 - res) << "%\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
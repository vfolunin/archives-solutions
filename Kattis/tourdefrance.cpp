#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int aSize;
    cin >> aSize;

    if (!aSize)
        return 0;

    int bSize;
    cin >> bSize;

    vector<int> a(aSize);
    for (int &x : a)
        cin >> x;

    vector<int> b(bSize);
    for (int &x : b)
        cin >> x;

    set<double> ratios;
    for (int ax : a)
        for (int bx : b)
            ratios.insert(1.0 * bx / ax);

    double maxSpread = 1;
    for (auto i = ratios.begin(), j = ++ratios.begin(); j != ratios.end(); i++, j++)
        maxSpread = max(maxSpread, *j / *i);

    cout.precision(2);
    cout << fixed << maxSpread << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double a;
    cin >> a;

    if (a < 0)
        return 0;

    cout.precision(10);
    cout << fixed << 2.64055930035883 * a << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
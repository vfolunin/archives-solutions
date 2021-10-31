#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double a, b = 12, vb, vc;
    if (!(cin >> a >> vb >> vc))
        return 0;

    double c = hypot(a, b);
    double tb = b / vb;
    double tc = c / vc;

    if (tc <= tb + 1e-9)
        cout << "S\n";
    else
        cout << "N\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
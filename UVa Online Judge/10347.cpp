#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double a, b, c;
    if (!(cin >> a >> b >> c))
        return 0;

    double p = (a + b + c) / 2;
    double r = p * (p - a) * (p - b) * (p - c);
    
    cout.precision(3);
    cout << fixed << (r > 0 ? sqrt(r) * 4 / 3 : -1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double whole = 0;
    for (char c; cin >> c; ) {
        if (c == '.')
            break;
        whole = whole * 2 + c - '0';
    }

    double frac = 0, value = 0.5;
    for (char c; cin >> c; value /= 2)
        if (c == '1')
            frac += value;

    cout.precision(15);
    cout << fixed << whole + frac;
}
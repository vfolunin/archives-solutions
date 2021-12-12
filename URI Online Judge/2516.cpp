#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double s, va, vb;
    if (!(cin >> s >> va >> vb))
        return 0;

    if (va <= vb) {
        cout << "impossivel\n";
    } else {
        cout.precision(2);
        cout << fixed << s / (va - vb) << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
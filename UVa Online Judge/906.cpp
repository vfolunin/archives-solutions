#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long double a, b, diff;
    if (!(cin >> a >> b >> diff))
        return 0;

    long double frac = a / b;
    for (int d = 1; 1; d++) {
        int c = frac * d;
        while ((long double)c / d <= frac)
            c++;

        if ((long double)c / d - frac <= diff + 1e-14) {
            cout << c << " " << d << "\n";
            break;
        }
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
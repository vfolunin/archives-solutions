#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int l, r, p;
    cin >> l >> r >> p;

    if (l == -1)
        return 0;

    double exponent = 0;
    for (int i = l; i <= r; i++)
        exponent = max(exponent, floor(p * log10(i)));

    double mantissa = 0;
    for (int i = l; i <= r; i++)
        mantissa += pow(10, p * log10(i) - exponent);

    while (mantissa >= 1) {
        mantissa /= 10;
        exponent++;
    }

    if (fabs(mantissa) < 1e-9)
        exponent = 1;

    cout << "Case " << setw(4) << setfill('0') << test << ": ";
    cout << fixed << setprecision(6) << mantissa << "e";
    cout << fixed << setprecision(0) << setw(10) << setfill('0') << exponent << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
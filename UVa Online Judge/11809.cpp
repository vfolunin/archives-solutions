#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string buf;
    cin >> buf;

    if (buf == "0e0")
        return 0;

    replace(buf.begin(), buf.end(), 'e', ' ');
    stringstream ss(buf);
    double mantissa, exponent;
    ss >> mantissa >> exponent;
    double val = log(mantissa) + exponent * log(10);

    for (int mantissaBits = 0; mantissaBits <= 10; mantissaBits++) {
        for (int exponentBits = 1; exponentBits <= 30; exponentBits++) {
            double m = log((1 << (mantissaBits + 1)) - 1) - (mantissaBits + 1) * log(2);
            double e = ((1 << exponentBits) - 1) * log(2);
            double curVal = m + e;

            if (fabs(curVal - val) <= 1e-5) {
                cout << mantissaBits << " " << exponentBits << "\n";
                return 1;
            }
        }
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
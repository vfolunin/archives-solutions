#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <complex>
using namespace std;

bool solve() {
    int decimal;
    if (!(cin >> decimal))
        return 0;

    string binary;
    while (decimal) {
        binary += '0' + decimal % 2;
        decimal /= 2;
    }
    reverse(binary.begin(), binary.end());

    complex<long long> complex = 0, complexBase = { -1, 1 };
    for (char c : binary) {
        complex *= complexBase;
        if (c == '1')
            complex += 1;
    }
    
    cout << complex.real() << " " << complex.imag() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
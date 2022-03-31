#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Fraction {
    int num, den;

    bool operator < (const Fraction &that) const {
        return num * that.den < that.num * den ||
               num * that.den == that.num * den && num < that.num;
    }
};

bool solve() {
    int fractionCount, numLimit;
    cin >> fractionCount >> numLimit;

    if (!fractionCount)
        return 0;

    vector<Fraction> fractions;
    for (int i = 0; i < fractionCount; i++) {
        Fraction fraction;
        cin >> fraction.num >> fraction.den;
        if (fraction.num <= numLimit)
            fractions.push_back(fraction);
    }

    if (fractions.empty()) {
        cout << "No suitable tickets offered\n";
    } else {
        sort(fractions.rbegin(), fractions.rend());
        cout << "Buy " << fractions[0].num << " tickets for $" << fractions[0].den << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
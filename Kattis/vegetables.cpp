#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Fraction {
    double num, den = 1;

    Fraction(double num) : num(num) {}

    bool operator < (const Fraction &that) const {
        return num * that.den > that.num * den;
    }

    double value() const {
        return num / den;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double ratio;
    int size;
    cin >> ratio >> size;

    multiset<Fraction> fractions;
    double minValue = 1e9;

    for (int i = 0; i < size; i++) {
        double value;
        cin >> value;

        fractions.insert(Fraction(value));
        minValue = min(minValue, value);
    }

    int res = 0;
    while (1) {
        Fraction fraction = *fractions.begin();
        fractions.erase(fractions.begin());

        if (minValue / fraction.value() > ratio)
            break;

        res++;
        fraction.den++;
        fractions.insert(fraction);
        minValue = min(minValue, fraction.value());
    }

    cout << res;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Mass {
    int amount;
    string unit;
    double mantissa;
    int exponent = 0;

    bool operator < (const Mass &that) const {
        if (exponent != that.exponent)
            return exponent < that.exponent;
        return mantissa < that.mantissa;
    }

    friend istream &operator >> (istream &in, Mass &mass) {
        in >> mass.amount >> mass.unit;

        mass.mantissa = mass.amount;

        if (mass.unit.front() != 'm')
            mass.exponent += 3;
        if (mass.unit.front() == 'k')
            mass.exponent += 3;
        if (mass.unit.front() == 'M')
            mass.exponent += 6;
        if (mass.unit.front() == 'G')
            mass.exponent += 9;
        if (mass.unit.back() == 'p')
            mass.mantissa *= 16380;
        if (mass.unit.back() == 't')
            mass.exponent += 6;

        while (mass.mantissa >= 10) {
            mass.mantissa /= 10;
            mass.exponent++;
        }

        return in;
    }

    friend ostream &operator << (ostream &out, Mass &mass) {
        return out << mass.amount << " " << mass.unit;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int massCount;
    cin >> massCount;

    vector<Mass> masses(massCount);
    for (Mass &mass : masses)
        cin >> mass;

    stable_sort(masses.begin(), masses.end());

    for (Mass &mass : masses)
        cout << mass << "\n";
}
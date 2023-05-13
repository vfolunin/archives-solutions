#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

struct Fraction {
    int num, den;

    Fraction(int num, int den) : num(num), den(den) {}

    bool operator < (const Fraction &that) const {
        return num * that.den < that.num *den;
    }

    friend ostream &operator << (ostream &out, Fraction &f) {
        return out << f.num << "/" << f.den;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int maxDen;
    cin >> maxDen;

    vector<Fraction> fractions;
    for (int den = 1; den <= maxDen; den++)
        for (int num = 1; num < den; num++)
            if (gcd(num, den) == 1)
                fractions.push_back(Fraction(num, den));

    sort(fractions.begin(), fractions.end());

    for (Fraction &fraction : fractions)
        cout << fraction << "\n";
}
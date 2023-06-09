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

    Fraction() {}

    Fraction(int n, int d) : num(n), den(d) {
        int g = gcd(num, den);
        num /= g;
        den /= g;

        if (den < 0) {
            num *= -1;
            den *= -1;
        }
    }

    Fraction operator + (const Fraction &that) const {
        return Fraction(num * that.den + that.num * den, den * that.den);
    }

    friend istream &operator >> (istream &in, Fraction &f) {
        int num, den;
        in >> num >> den;

        f = Fraction(num, den);

        return in;
    }

    friend ostream &operator << (ostream &out, const Fraction &f) {
        auto [num, den] = f;
        
        if (num < 0) {
            cout << "-";
            num *= -1;
        }

        int whole = num / den, remainder = num % den;

        if (whole)
            out << whole;
        if (whole && remainder)
            out << " ";
        if (remainder)
            out << remainder << "/" << den;
        if (!whole && !remainder)
            out << 0;

        return out;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Fraction a, b;
    cin >> a >> b;

    cout << a + b;
}
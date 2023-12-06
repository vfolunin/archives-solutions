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
        out << f.num;
        if (f.den != 1)
            out << " " << f.den;
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
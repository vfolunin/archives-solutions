#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

struct Fraction {
    long long num, den;

    Fraction(long long n = 0, long long d = 1) : num(n), den(d) {
        long long g = gcd(num, den);
        num /= g;
        den /= g;

        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

    friend istream &operator >> (istream &in, Fraction &f) {
        long long num, den;
        in >> num >> den;
        f = { num, den };
        return in;
    }

    friend ostream &operator << (ostream &out, const Fraction &f) {
        int whole = f.num / f.den, frac = f.num % f.den;
        if (whole) {
            out << whole;
            if (frac)
                out << " ";
        }
        if (frac) {
            out << frac;
            if (f.den != 1)
                out << "/" << f.den;
        }
        if (!whole && !frac)
            cout << 0;
        return out;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Fraction f;
    cin >> f;

    cout << f << "\n";
}
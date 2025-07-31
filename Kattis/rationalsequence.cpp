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

    Fraction operator + (const Fraction &that) const {
        return { num * that.den + that.num * den, den * that.den };
    }

    Fraction operator - (const Fraction &that) const {
        return { num * that.den - that.num * den, den * that.den };
    }

    Fraction operator * (const Fraction &that) const {
        return { num * that.num, den * that.den };
    }

    Fraction operator / (const Fraction &that) const {
        return { num * that.den, den * that.num };
    }

    friend istream &operator >> (istream &in, Fraction &f) {
        long long num, den = 1;
        in >> num;
        if (in.peek() == '/') {
            in.ignore();
            in >> den;
        }
        f = { num, den };
        return in;
    }

    friend ostream &operator << (ostream &out, const Fraction &f) {
        out << f.num;
        if (f.den != 1)
            out << "/" << f.den;
        return out;
    }
};

void solve() {
    int test;
    Fraction fraction;
    cin >> test >> fraction;

    cout << test << " " << Fraction(1) / (Fraction(fraction.num / fraction.den) * 2 + 1 - fraction) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
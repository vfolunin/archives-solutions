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
        long long sign = 1, whole = 0, num = 0, den = 1;
        
        in >> num;
        if (in.peek() == ' ') {
            whole = num;
            in >> num;
        }
        if (in.peek() == '/') {
            in.ignore();
            in >> den;
        }
        
        if (whole < 0 || num < 0) {
            sign = -1;
            whole = abs(whole);
            num = abs(num);
        }

        f = { sign * (whole * den + num), den };
        return in;
    }

    friend ostream &operator << (ostream &out, const Fraction &f) {
        if (!f.num)
            return out << 0;
        if (f.num < 0)
            out << "-";
        if (f.num / f.den)
            out << abs(f.num / f.den);
        if (f.num / f.den && f.num % f.den)
            out << " ";
        if (f.num % f.den)
            out << abs(f.num % f.den) << "/" << f.den;
        return out;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Fraction a, b;
    char op;

    cin >> a >> op >> b;

    if (op == '+')
        cout << a + b;
    else if (op == '-')
        cout << a - b;
    else if (op == '*')
        cout << a * b;
    else
        cout << a / b;
}
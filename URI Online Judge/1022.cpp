#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

struct Fraction {
    int num, den;

    Fraction operator + (const Fraction &that) {
        return { num * that.den + that.num * den, den * that.den };
    }
    Fraction operator - (const Fraction &that) {
        return { num * that.den - that.num * den, den * that.den };
    }
    Fraction operator * (const Fraction &that) {
        return { num * that.num, den * that.den };
    }
    Fraction operator / (const Fraction &that) {
        return { num * that.den, den * that.num };
    }
    Fraction reduce() {
        int g = gcd(num, den);
        Fraction res = { num / g, den / g };
        if (res.den < 0) {
            res.num *= -1;
            res.den *= -1;
        }
        return res;
    }
};

istream &operator >> (istream &in, Fraction &f) {
    char dash;
    in >> f.num >> dash >> f.den;
    return in;
}

ostream &operator << (ostream &out, const Fraction &f) {
    out << f.num << "/" << f.den;
    return out;
}

void solve() {
    Fraction a, b, c;
    char op;
    cin >> a >> op >> b;

    if (op == '+')
        c = a + b;
    else if (op == '-')
        c = a - b;
    else if (op == '*')
        c = a * b;
    else
        c = a / b;

    cout << c << " = " << c.reduce() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
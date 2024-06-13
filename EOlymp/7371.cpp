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

    friend istream &operator >> (istream &in, Fraction &f) {
        long long num, den;
        in >> num >> den;
        f = { num, den };
        return in;
    }

    friend ostream &operator << (ostream &out, const Fraction &f) {
        return out << f.num << " " << f.den;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Fraction a, b;
    cin >> a >> b;

    cout << a + b;
}
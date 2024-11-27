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

    Fraction operator * (const Fraction &that) const {
        return { num * that.num, den * that.den };
    }

    friend istream &operator >> (istream &in, Fraction &f) {
        long long num, den = 1;
        in >> num;
        in.ignore();
        in >> den;
        f = { num, den };
        return in;
    }

    friend ostream &operator << (ostream &out, const Fraction &f) {
        return out << f.num << "/" << f.den;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Fraction a, b;
    int n;
    cin >> a >> b >> n;

    cout << a + (b * Fraction(n - 1));
}
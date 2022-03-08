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

    void normalize() {
        long long d = gcd(num, den);
        num /= d;
        den /= d;
        if (den < 0) {
            num *= -1;
            den *= -1;
        }
    }

    Fraction(long long num = 0, long long den = 1) : num(num), den(den) {
        normalize();
    }

    Fraction operator + (const Fraction &that) const {
        return Fraction(num * that.den + that.num * den, den * that.den);
    }

    Fraction operator - (const Fraction &that) const {
        return Fraction(num * that.den - that.num * den, den * that.den);
    }

    Fraction operator * (const Fraction &that) const {
        return Fraction(num * that.num, den * that.den);
    }

    Fraction operator / (const Fraction &that) const {
        return Fraction(num * that.den, den * that.num);
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Fraction temperature;
    char slash;
    cin >> temperature.num >> slash >> temperature.den;

    temperature = temperature - Fraction(32, 1);
    temperature = temperature * Fraction(5, 9);

    cout << temperature.num << "/" << temperature.den;
}
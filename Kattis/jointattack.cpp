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

    int coefficientCount;
    cin >> coefficientCount;

    vector<long long> coefficients(coefficientCount);
    for (long long &coefficient : coefficients)
        cin >> coefficient;

    Fraction res(coefficients.back(), 1);
    for (int i = coefficientCount - 2; i >= 0; i--)
        res = Fraction(coefficients[i], 1) + Fraction(res.den, res.num);

    cout << res.num << "/" << res.den;
}
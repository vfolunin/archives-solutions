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
    }

    Fraction(long long num, long long den) : num(num), den(den) {
        normalize();
    }

    Fraction operator + (const Fraction &that) const {
        return Fraction(num * that.den + that.num * den, den * that.den);
    }

    Fraction operator * (const Fraction &that) const {
        return Fraction(num * that.num, den * that.den);
    }
};

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    Fraction res(0, 1);
    for (int i = 1; i <= n; i++)
        res = res + Fraction(1, i);
    res = res * Fraction(n, 1);

    if (res.num % res.den == 0) {
        cout << res.num / res.den << "\n";
        return 1;
    }

    string num = to_string(res.num % res.den);
    string den = to_string(res.den);
    string bar(den.size(), '-');

    if (res.num > res.den) {
        string whole = to_string(res.num / res.den) + " ";
        num = string(whole.size(), ' ') + num;
        den = string(whole.size(), ' ') + den;
        bar = whole + bar;
    }

    cout << num << "\n";
    cout << bar << "\n";
    cout << den << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

struct Fraction {
    long long num, den;

    void normalize() {
        long long d = gcd(num, den);
        num /= d;
        den /= d;
    }

    Fraction(long long num = 0, long long den = 1) : num(num), den(den) {
        normalize();
    }

    Fraction operator + (const Fraction &that) const {
        return Fraction(num * that.den + that.num * den, den * that.den);
    }
};

void solve(int test) {
    int restaurantCount;
    cin >> restaurantCount;

    Fraction res(0, 1);

    for (int i = 0; i < restaurantCount; i++) {
        int num, den;
        cin >> den >> num;
        res = res + Fraction(num, den);
    }

    cout << "Case " << test << ": " << res.num << "/" << res.den << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
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
        string dash;
        in >> num >> dash >> den;
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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Fraction fraction;
    cin >> fraction;

    cout << fraction;
}
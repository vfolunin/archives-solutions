#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Fraction {
    string s;
    long long num, den;
    pair<long long, long long> p;

    bool greater(const Fraction &that) const {
        return num * that.den > that.num * den && p > that.p;
    }

    friend istream &operator >> (istream &in, Fraction &f) {
        in >> f.s;

        stringstream ss(f.s);
        long long whole;
        char dot;
        string frac;
        ss >> whole >> dot >> frac;

        f.num = whole;
        f.den = 1;
        for (char c : frac) {
            f.num = f.num * 10 + c - '0';
            f.den *= 10;
        }

        f.p = { whole, stoll(frac) };

        return in;
    }

    friend ostream &operator << (ostream &out, const Fraction &f) {
        return out << f.s;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Fraction a, b;
    cin >> a >> b;

    if (a.greater(b))
        cout << a;
    else if (b.greater(a))
        cout << b;
    else
        cout << -1;
}
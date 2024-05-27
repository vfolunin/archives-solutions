#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Fraction {
    long long num, den;

    Fraction(long long n = 0, long long d = 1) : num(n), den(d) {}

    bool operator < (const Fraction &that) const {
        return num * that.den < that.num * den;
    }

    friend istream &operator >> (istream &in, Fraction &f) {
        long long num, den = 1;
        in >> num;
        if (in.peek() == '/') {
            in.ignore();
            in >> den;
        }
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
    cin >> a >> b;

    cout << min(a, b) << " " << max(a, b);
}
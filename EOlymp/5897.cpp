#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class ModInt {
    long long value;
    static const long long mod = 1e9 + 9;

    static long long gcdex(long long a, long long b, long long &x, long long &y) {
        if (!b) {
            x = 1;
            y = 0;
            return a;
        }
        long long x1, y1, d = gcdex(b, a % b, x1, y1);
        x = y1;
        y = x1 - a / b * y1;
        return d;
    }

public:
    ModInt(long long value = 0) : value((value %mod + mod) % mod) {}

    ModInt operator + (const ModInt &that) const {
        return value + that.value;
    }

    ModInt operator - (const ModInt &that) const {
        return value - that.value;
    }

    ModInt operator * (const ModInt &that) const {
        return value * that.value;
    }

    ModInt operator / (const ModInt &that) const {
        long long x, y;
        gcdex(that.value, mod, x, y);
        return value * x;
    }

    friend istream &operator >> (istream &in, ModInt &m) {
        long long value;
        in >> value;
        m = ModInt(value);
        return in;
    }

    friend ostream &operator << (ostream &out, const ModInt &m) {
        return out << m.value;
    }
};

ModInt squareSumTo(long long n) {
    return ModInt(n) * (n + 1) * (2 * n + 1) / 6;
}

ModInt squareSum(long long l, long long r) {
    if (l > r)
        return squareSum(r, l);
    
    if (l < 0) {
        if (r < 0)
            return squareSum(-r, -l);
        else
            return squareSumTo(-l) + squareSumTo(r);
    }

    return squareSumTo(r) - (l ? squareSumTo(l - 1) : 0);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long l, r;
    cin >> l >> r;

    cout << squareSum(l, r);
}
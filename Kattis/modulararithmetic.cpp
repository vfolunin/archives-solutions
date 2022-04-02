#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

class ModInt {
    long long value;

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
    static long long mod;

    ModInt(long long value = 0) : value((value % mod + mod) % mod) {}

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

    bool canDivide(const ModInt &that) const {
        long long x, y;
        return that.value && gcdex(that.value, mod, x, y) == 1;
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

long long ModInt::mod;

bool solve() {
    int opCount;
    cin >> ModInt::mod >> opCount;

    if (!opCount)
        return 0;

    for (int i = 0; i < opCount; i++) {
        ModInt a, b;
        char op;
        cin >> a >> op >> b;

        if (op == '+')
            cout << a + b << "\n";
        else if (op == '-')
            cout << a - b << "\n";
        else if (op == '*')
            cout << a * b << "\n";
        else if (op == '/' && a.canDivide(b))
            cout << a / b << "\n";
        else
            cout << "-1\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
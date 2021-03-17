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

struct Ratio {
    long long num, den;

    void normalize() {
        long long g = gcd(num, den);
        num /= g;
        den /= g;
    }

    Ratio(long long num = 0, long long den = 1) : num(num), den(den) {
        normalize();
    }

    Ratio operator + (const Ratio &that) const {
        return Ratio(num * that.den + that.num * den, den * that.den);
    }

    Ratio operator / (const Ratio &that) const {
        return Ratio(num * that.den, den * that.num);
    }
};

ostream &operator << (ostream &out, const Ratio &r) {
    out << r.num << "/" << r.den;
    return out;
}

void solve(int test) {
    int n;
    cin >> n;

    Ratio r;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        r = r + Ratio(1, x);
    }

    cout << "Case " << test << ": " << Ratio(n) / r << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
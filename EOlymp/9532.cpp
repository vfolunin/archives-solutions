#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <complex>
using namespace std;

istream &operator >> (istream &in, complex<double> &c) {
    int re, im;
    char i;
    in >> re >> im >> i;
    c = complex<double>(re, im);
    return in;
}

ostream &operator << (ostream &out, const complex<double> &c) {
    out.precision(2);
    return out << fixed << c.real() << (c.imag() >= 0 ? "+" : "") << c.imag() << "i";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    complex<double> a, b;
    char op;

    while (cin >> a >> op >> b)
        cout << (op == '*' ? a * b : a / b) << "\n";
}
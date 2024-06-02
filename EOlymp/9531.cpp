#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <complex>
using namespace std;

istream &operator >> (istream &in, complex<int> &c) {
    int re, im;
    char i;
    in >> re >> im >> i;
    c = complex<int>(re, im);
    return in;
}

ostream &operator << (ostream &out, const complex<int> &c) {
    return out << c.real() << (c.imag() >= 0 ? "+" : "") << c.imag() << "i";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    complex<int> a, b;
    char op;

    while (cin >> a >> op >> b)
        cout << (op == '+' ? a + b : a - b) << "\n";
}
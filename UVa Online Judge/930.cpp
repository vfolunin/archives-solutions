#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Polynomial {
    vector<double> coeff;

    void divide(double root) {
        vector<double> quotientCoeff(coeff.size() - 1);
        for (int i = coeff.size() - 1; i > 0; i--) {
            quotientCoeff[i - 1] = coeff[i];
            coeff[i - 1] += quotientCoeff[i - 1] * root;
        }
        coeff = quotientCoeff;
    }

    pair<double, double> solve2() {
        double a = coeff[2], b = coeff[1], c = coeff[0];
        double d = b * b - 4 * a * c;
        double x1 = (-b - sqrt(d)) / (2 * a);
        double x2 = (-b + sqrt(d)) / (2 * a);
        if (x1 < x2)
            swap(x1, x2);
        return { x1, x2 };
    }
};

istream &operator >> (istream &in, Polynomial &p) {
    int degree;
    in >> degree;
    p.coeff.resize(degree + 1);
    for (int i = degree; i >= 0; i--)
        in >> p.coeff[i];
    return in;
}

void solve() {
    Polynomial p;
    cin >> p;

    while (p.coeff.size() > 3) {
        double root;
        cin >> root;
        p.divide(root);
    }

    auto [x1, x2] = p.solve2();

    cout.precision(1);
    cout << fixed << x1 << "\n";
    cout << fixed << x2 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
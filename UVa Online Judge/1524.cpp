#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double eval(vector<double> &coeff, double x) {
    double res = 0;
    for (double c : coeff)
        res = res * x + c;
    return res;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<double> coeff(n + 1);
    for (int power = n; power >= 0; power--) {
        cin >> coeff[power];
        coeff[power] /= power + 1;
    }
    reverse(coeff.begin(), coeff.end());

    double l, r;
    cin >> l >> r;

    double res = (eval(coeff, r) * r - eval(coeff, l) * l) / (r - l);

    cout.precision(3);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
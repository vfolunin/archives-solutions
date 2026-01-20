#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double f(vector<double> &coeff, double x) {
    double res = 0;
    for (int i = coeff.size() - 1; i >= 0; i--)
        res = res * x + coeff[i];
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double l, r;
    cin >> l >> r;

    int size;
    cin >> size;

    vector<double> coeff(size + 2);
    for (int i = 1; i <= size + 1; i++) {
        cin >> coeff[i];
        coeff[i] /= i;
    }

    cout << fixed << f(coeff, r) - f(coeff, l);
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double getIntegral(vector<double> &coeffs, double x) {
    double res = 0;
    for (int i = coeffs.size() - 1; i >= 0; i--)
        res = res * x + coeffs[i];
    return res * x;
}

double getVolume(vector<double> &coeffs, double xl, double xr) {
    return getIntegral(coeffs, xr) - getIntegral(coeffs, xl);
}

double getX(vector<double> &coeffs, double xl, double targetVolume) {
    double l = 0, r = 1e9;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (getVolume(coeffs, xl, xl + m) < targetVolume)
            l = m;
        else
            r = m;
    }
    return l;
}

bool solve(int test) {
    int degree;
    if (!(cin >> degree))
        return 0;

    vector<double> coeffs(degree + 1);
    for (double &c : coeffs)
        cin >> c;

    vector<double> coeffs2(coeffs.size() * 2 - 1);
    for (int i = 0; i < coeffs.size(); i++)
        for (int j = 0; j < coeffs.size(); j++)
            coeffs2[i + j] += acos(-1) * coeffs[i] * coeffs[j] / (i + j + 1);

    double xl, xr, deltaVolume;
    cin >> xl >> xr >> deltaVolume;

    double totalVolume = getVolume(coeffs2, xl, xr);

    cout.precision(2);
    cout << "Case " << test << ": " << fixed << totalVolume << "\n";
    if (totalVolume < deltaVolume) {
        cout << "insufficient volume\n";
    } else {
        double volume = deltaVolume;
        for (int i = 0; i < 8 && volume < totalVolume; i++, volume += deltaVolume)
            cout << (i ? " " : "") << getX(coeffs2, xl, volume);
        cout << "\n";
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
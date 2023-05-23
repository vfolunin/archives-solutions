#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double f(double a, double b, double c, double x) {
    return a * x * x + b * x + c;
}

double find(double a, double b, double c) {
    double l = -1e9, r = 1e9;
    for (int i = 0; i < 200; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (f(a, b, c, m1) < f(a, b, c, m2))
            r = m2;
        else
            l = m1;
    }
    return f(a, b, c, l);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double a, b, c;
    cin >> a >> b >> c;

    cout << fixed << find(a, b, c);
}
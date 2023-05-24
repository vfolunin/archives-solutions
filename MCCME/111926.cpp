#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double f(double a, double b, double x) {
    double y = 1 / x;
    return a * x * x + b * y * y;
}

double find(double a, double b) {
    double l = 0, r = 1e9;
    for (int i = 0; i < 200; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        if (f(a, b, m1) < f(a, b, m2))
            r = m2;
        else
            l = m1;
    }
    return l;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double a, b;
    cin >> a >> b;

    double x = find(a, b), y = 1 / x;

    cout << fixed << x << " " << y;
}
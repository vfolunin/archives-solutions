#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double solveEquation(double a, double b, double c) {
    double d = b * b - 4 * a * c;
    double x1 = (-b - sqrt(d)) / (2 * a);
    double x2 = (-b + sqrt(d)) / (2 * a);
    return max(x1, x2);
}

bool solve(int test) {
    int type;
    cin >> type;

    if (!type)
        return 0;

    cout << "Case " << test << ": ";
    cout.precision(3);

    if (type == 1) {
        double v0, v, t;
        cin >> v0 >> v >> t;
        double a = (v - v0) / t;
        double s = v0 * t + a * t * t / 2;
        cout << fixed << s << " " << a << "\n";
    } else if (type == 2) {
        double v0, v, a;
        cin >> v0 >> v >> a;
        double t = (v - v0) / a;
        double s = v0 * t + a * t * t / 2;
        cout << fixed << s << " " << t << "\n";
    } else if (type == 3) {
        double v0, a, s;
        cin >> v0 >> a >> s;
        double t = solveEquation(a / 2, v0, -s);
        double v = v0 + a * t;
        cout << fixed << v << " " << t << "\n";
    } else {
        double v, a, s;
        cin >> v >> a >> s;
        double v0 = sqrt(v * v - s * 2 * a);
        double t = (v - v0) / a;
        cout << fixed << v0 << " " << t << "\n";
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}
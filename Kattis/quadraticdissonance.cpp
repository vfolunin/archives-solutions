#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double f(double a, double b, double c, double d, double x) {
    return x * x + max(a * x + b, c * x + d);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<double> xs = { -a / 2, -c / 2 };
    if (a != c)
        xs.push_back((d - b) / (a - c));

    double resX, resY = 1e100;
    for (double x : xs) {
        double y = f(a, b, c, d, x);
        if (resY > y) {
            resX = x;
            resY = y;
        }
    }

    cout << fixed << resX << " " << resY;
}
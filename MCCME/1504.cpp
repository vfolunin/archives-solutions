#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double a, b, c;
    cin >> a >> b >> c;

    cout.precision(2);
    cout << fixed;

    if (a) {
        double d = b * b - 4 * a * c;
        if (d < 0) {
            cout << "0";
        } else if (d < 1e-9) {
            cout << "3 " << -b / (2 * a);
        } else {
            double x1 = (-b - sqrt(d)) / (2 * a);
            double x2 = (-b + sqrt(d)) / (2 * a);
            if (x1 > x2)
                swap(x1, x2);
            cout << "2 " << x1 << " " << x2;
        }
    } else if (b) {
        cout << "1 " << -c / b;
    } else if (c) {
        cout << "0";
    } else {
        cout << "-1";
    }
}
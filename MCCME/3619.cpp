#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double EPS = 1e-9;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double a, b, c;
    cin >> a >> b >> c;

    if (fabs(a)) {
        double d = b * b - 4 * a * c;
        if (d < -EPS) {
            cout << "0";
        } else if (d < EPS) {
            cout << "1 " << fixed << -b / (2 * a);
        } else {
            double x1 = (-b - sqrt(d)) / (2 * a);
            double x2 = (-b + sqrt(d)) / (2 * a);
            if (x1 > x2)
                swap(x1, x2);
            cout << "2 " << fixed << x1 << " " << x2;
        }
    } else if (fabs(b)) {
        cout << "1 " << fixed << -c / b;
    } else if (fabs(c)) {
        cout << "0";
    } else {
        cout << "3";
    }
}
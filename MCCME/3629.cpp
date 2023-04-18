#include <iostream>
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

    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    if (abs(a) < abs(c)) {
        swap(a, c);
        swap(b, d);
        swap(e, f);
    }

    if (abs(a) >= EPS) {
        double k = c / a;
        c -= a * k;
        d -= b * k;
        f -= e * k;

        if (abs(d) >= EPS) {
            double y = f / d;
            double x = (e - b * y) / a;
            cout << "2 " << fixed << x << " " << y;
        } else if (abs(f) >= EPS) {
            cout << "0";
        } else if (abs(b) >= EPS) {
            double k = -a / b;
            double p = e / b;
            cout << "1 " << fixed << k << " " << p;
        } else {
            double x = e / a;
            cout << "3 " << fixed << x;
        }
    } else {
        if (abs(b) < abs(d)) {
            swap(b, d);
            swap(e, f);
        }

        if (abs(b) >= EPS) {
            double k = d / b;
            d -= b * k;
            f -= e * k;

            if (abs(f) >= EPS) {
                cout << "0";
            } else {
                double y = e / b;
                cout << "4 " << fixed << y;
            }
        } else {
            if (abs(e) >= EPS || abs(f) >= EPS) {
                cout << "0";
            } else {
                cout << "5";
            }
        }
    }
}
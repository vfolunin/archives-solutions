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

    double d = b * b - 4 * a * c;
    if (d > 1e-9) {
        double xa = (-b - sqrt(d)) / (2 * a);
        double xb = (-b + sqrt(d)) / (2 * a);
        if (xa > xb)
            swap(xa, xb);
        cout << fixed << xa << " " << xb;
    } else if (d > -1e-9) {
        cout << fixed << -b / (2 * a);
    }
}
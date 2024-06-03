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

    for (string type; cin >> type; ) {
        if (type == "Square") {
            double a;
            cin >> a;

            cout << fixed << 4 * a << " " << a * a << "\n";
        } else if (type == "Rectangle") {
            double h, w;
            cin >> h >> w;

            cout << fixed << 2 * (h + w) << " " << h * w << "\n";
        } else {
            double a, b, c;
            cin >> a >> b >> c;

            double p = (a + b + c) / 2;

            cout << fixed << p * 2 << " " << sqrt(p * (p - a) * (p - b) * (p - c)) << "\n";
        }
    }
}
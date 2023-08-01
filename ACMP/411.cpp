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

    if (a) {
        double d = b * b - 4 * a * c;
        if (d > 0) {
            cout << "2\n";
            cout << fixed << (-b - sqrt(d)) / (2 * a) << "\n";
            cout << fixed << (-b + sqrt(d)) / (2 * a);
        } else if (d == 0) {
            cout << "1\n";
            cout << fixed << -b / (2 * a);
        } else {
            cout << 0;
        }
    } else if (b) {
        cout << "1\n";
        cout << fixed << -c / b;
    } else if (c) {
        cout << 0;
    } else {
        cout << -1;
    }
}
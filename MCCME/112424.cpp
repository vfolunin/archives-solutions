#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double a, b, c;
    for (int i = 0; i < 3; i++) {
        double sign = 1;
        if (cin.peek() == '+' || cin.peek() == '-') {
            if (cin.peek() == '-')
                sign = -1;
            cin.get();
        }

        double value = 1;
        if (isdigit(cin.peek()))
            cin >> value;

        if (cin.peek() == 'a') {
            a = sign * value;
            cin.get();
        } else if (cin.peek() == 'b') {
            b = sign * value;
            cin.get();
        } else {
            c = sign * value;
        }
    }

    double d = b * b - 4 * a * c;

    cout.precision(3);
    if (d > 0) {
        double x1 = (-b - sqrt(d)) / (2 * a);
        double x2 = (-b + sqrt(d)) / (2 * a);
        if (x1 > x2)
            swap(x1, x2);

        cout << fixed << x1 << " " << x2;
    } else if (d == 0) {
        cout << fixed << -b / (2 * a);
    }
}
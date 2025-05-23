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
    if (d > 0) {
        double x1 = (-b - sqrt(d)) / (2 * a);
        double x2 = (-b + sqrt(d)) / (2 * a);
        if (x1 > x2)
            swap(x1, x2);

        cout << "2\n" << fixed << x1 << " " << x2;        
    } else if (d == 0) {
        cout << "1\n" << fixed << -b / (2 * a);
    } else {
        cout << 0;
    }
}
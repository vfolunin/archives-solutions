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
    if (d >= 0 && a > 0) {
        cout.precision(5);
        cout << "R1 = " << fixed << (-b + sqrt(d)) / (2 * a) << "\n";
        cout << "R2 = " << fixed << (-b - sqrt(d)) / (2 * a) << "\n";
    } else {
        cout << "Impossivel calcular\n";
    }
}
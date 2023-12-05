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

    double d, p;
    cin >> d >> p;

    double a = sqrt(d * d / 2);
    double h = sqrt(p * p - a * a);
    double l = sqrt(h * h + d * d / 4);

    cout.precision(3);
    cout << fixed << d * d + 2 * d * l << " " << d * d * h / 3;
}
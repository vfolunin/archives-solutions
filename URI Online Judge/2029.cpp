#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double volume, diameter;
    if (!(cin >> volume >> diameter))
        return 0;

    double radius = diameter / 2;
    double area = 3.14 * radius * radius;
    double height = volume / area;

    cout.precision(2);
    cout << "ALTURA = " << fixed << height << "\n";
    cout << "AREA = " << fixed << area << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
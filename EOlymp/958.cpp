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

    double b, angle;
    cin >> b >> angle;
    angle *= acos(-1) / 180;

    double c = 2 * b * cos(angle);
    double a = c / sqrt(2);
    double l = sqrt(b * b - a * a / 4);

    cout << fixed << a * a + 2 * a * l;
}
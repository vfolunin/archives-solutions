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

    double v, h;
    cin >> v >> h;

    double a = sqrt(3 * v / h);
    double b = hypot(h, a / 2);

    cout.precision(1);
    cout << fixed << 2 * a * b;
}
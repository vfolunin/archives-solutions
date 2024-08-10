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

    a = 1 / a;
    b = 1 / b;
    c = 1 / c;

    cout.precision(4);
    cout << fixed << 1 / (a + b + c + 2 * sqrt(a * b + a * c + b * c));
}
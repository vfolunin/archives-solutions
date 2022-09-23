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
    cin >> a >> b >> c;

    double d = b * b - 4 * a * c;

    if (d > 0)
        cout << fixed << (-b - sqrt(d)) / (2 * a) << " " << (-b + sqrt(d)) / (2 * a);
    else if (d == 0)
        cout << fixed << -b / (2 * a);
}
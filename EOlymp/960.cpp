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

    double r1, r2, h;
    cin >> r1 >> r2 >> h;

    double l = hypot(r1 - r2, h);

    cout << fixed << acos(-1) * (l * (r1 + r2) + r1 * r1 + r2 * r2);
}
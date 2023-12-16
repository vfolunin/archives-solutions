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

    double area, diff;
    cin >> area >> diff;

    double a = 1, b = diff, c = -2 * area;
    double d = b * b - 4 * a * c;

    cout << fixed << (-b + sqrt(d)) / (2 * a);
}
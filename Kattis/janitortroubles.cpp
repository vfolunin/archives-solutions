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

    double a, b, c, d;
    cin >> a >> b >> c >> d;

    double p = (a + b + c + d) / 2;

    cout << fixed << sqrt((p - a) * (p - b) * (p - c) * (p - d));
}
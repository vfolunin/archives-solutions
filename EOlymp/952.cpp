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

    double a, h;
    cin >> a >> h;

    double b = hypot(a / 2, h);

    cout.precision(1);
    cout << fixed << a * a + a * b * 2;
}
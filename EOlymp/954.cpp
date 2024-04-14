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

    double a, b, h;
    cin >> a >> b >> h;

    double c = hypot((a - b) / 2, h);

    cout.precision(2);
    cout << fixed << (a + b) * c * 2;
}
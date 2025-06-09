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

    double r, h;
    cin >> r >> h;

    double a = 4 * acos(-1) * (r * r * r) / 3;
    double b = acos(-1) * h * h * (r - h / 3);

    cout << fixed << a - b;
}
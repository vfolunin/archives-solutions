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

    double x, y;
    cin >> x >> y;

    cout << fixed << 2 * x * y / sqrt(x * x + y * y) - (x + y - 1) * (x + y - 1) / (x * y);
}
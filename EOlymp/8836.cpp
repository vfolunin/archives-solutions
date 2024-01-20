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

    double x, y;
    cin >> x >> y;

    cout << fixed << (x - y) * (x - y) / sqrt(x * x + y * y - 1) + sqrt(x * x + y * y - 1) / (2 * x * y);
}
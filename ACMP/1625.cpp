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

    double a, b;
    cin >> a >> b;

    if (a > b)
        swap(a, b);

    double c = max((a * sqrt(2) - b) / 2, 0.0);

    cout << fixed << b * b + 4 * c * c;
}
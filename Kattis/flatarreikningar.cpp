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

    double volume;
    cin >> volume;

    double radius = cbrt(volume * 3 / 4 / acos(-1));

    cout << fixed << 4 * acos(-1) * radius * radius;
}
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

    double t, h;
    cin >> t >> h;

    if (h >= 2 * t)
        cout << fixed << sqrt(2 * t * h);
    else
        cout << fixed << t + h / 2;
}
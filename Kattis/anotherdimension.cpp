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

    double d;
    cin >> d;

    double r = d / 2;

    cout.precision(9);
    cout << fixed << acos(-1) * 2 / 3 * r * r * r;
}
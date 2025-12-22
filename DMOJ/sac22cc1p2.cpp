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

    cout << fixed << (a * c - acos(-1) * d * d / 4) * b;
}
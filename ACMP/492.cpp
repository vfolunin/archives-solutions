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

    long double x, y, vx, vy, v, t, d;
    cin >> x >> y >> vx >> vy >> v >> t >> d;

    x += vx * t;
    y += vy * t;

    long double r = abs(hypotl(x, y) - d);

    cout << (v * t >= r ? "YES" : "NO");
}
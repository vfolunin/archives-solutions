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

    double d, h, v, e;
    cin >> d >> h >> v >> e;

    double r = d / 2;
    double s = acos(-1.0) * r * r;
    v -= s * e;

    if (v > 0)
        cout << "YES\n" << s * h / v;
    else
        cout << "NO";
}
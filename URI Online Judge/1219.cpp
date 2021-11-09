#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double a, b, c;
    if (!(cin >> a >> b >> c))
        return 0;

    double p = (a + b + c) / 2;
    double s2 = sqrt(p * (p - a) * (p - b) * (p - c));

    double pi = acos(-1.0);
    double r1 = a * b * c / (4 * s2);
    double s1 = pi * r1 * r1;

    double r3 = sqrt((p - a) * (p - b) * (p - c) / p);
    double s3 = pi * r3 * r3;

    s1 -= s2;
    s2 -= s3;

    cout.precision(4);
    cout << fixed << s1 << " " << s2 << " " << s3 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
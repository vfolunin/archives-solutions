#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double ra, rb, rc;
    cin >> ra >> rb >> rc;

    double a = rb + rc;
    double b = ra + rc;
    double c = ra + rb;
    double p = (a + b + c) / 2;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));

    double alpha = acos((b * b + c * c - a * a) / (2 * b * c));
    area -= alpha / 2 * ra * ra;
    double beta = acos((a * a + c * c - b * b) / (2 * a * c));
    area -= beta / 2 * rb * rb;
    double gamma = acos((a * a + b * b - c * c) / (2 * a * b));
    area -= gamma / 2 * rc * rc;

    cout << fixed << area << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
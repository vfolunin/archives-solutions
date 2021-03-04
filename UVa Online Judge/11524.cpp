#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double r, m1, n1, m2, n2, m3, n3;
    cin >> r >> m1 >> n1 >> m2 >> n2 >> m3 >> n3;

    double a = n1 / m1 + 1;
    double b = m3 / n3 + 1;
    double c = a + b - 2;
    double p = (a + b + c) / 2;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    double r1 = s / p;

    cout << fixed << s * pow(r / r1, 2) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
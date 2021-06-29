#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double a, b, s;
    cin >> a >> b >> s;

    double p = 1;
    if (s) {
        double l = s / b, r = a;
        if (l <= r) {
            double notGreaterArea = l * b + s * (log(r) - log(l));
            double totalArea = a * b;
            p = 1 - notGreaterArea / totalArea;
        } else {
            p = 0;
        }
    }

    cout.precision(6);
    cout << fixed << 100 * p << "%\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
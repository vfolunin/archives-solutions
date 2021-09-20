#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    double p = (a + b + c + d) / 2;
    double s = sqrt((p - a) * (p - b) * (p - c) * (p - d));

    cout.precision(2);
    cout << fixed << s << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
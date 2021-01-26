#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double d, l;
    cin >> d >> l;

    double a = l / 2;
    double b = sqrt(l * l / 4 - d * d / 4);

    cout.precision(3);
    cout << fixed << acos(-1.0) * a * b << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
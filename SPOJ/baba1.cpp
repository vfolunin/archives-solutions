#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double c, area;
    cin >> c >> area;

    double product = 2 * area;
    double sum = sqrt(c * c + 2 * product);
    double d = sum * sum - 4 * product;

    if (d >= 0) {
        double a = (sum + sqrt(d)) / 2;
        double b = sum - a;
        if (a > b)
            swap(a, b);

        cout << fixed << a << " " << b << " " << c << "\n";
    } else {
        cout << "-1\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}
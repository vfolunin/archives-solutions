#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    double d, n;
    cin >> d >> n;

    double r = d / (n - 1);
    double c = 2 * acos(-1) * (r + d);

    cout.precision(3);
    cout << "Case " << test << ": " << fixed << c << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
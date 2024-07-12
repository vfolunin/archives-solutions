#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    double r, d, h1;
    cin >> r >> d >> h1;

    double oe = r - d;
    double ae = sqrt(r * r - oe * oe);
    double ab = ae * 2;
    double eg = r - h1;
    double obg = asin(eg / r);
    double obe = asin(oe / r);
    double ebg = obg - obe;
    double h2 = h1 + ab * sin(ebg);

    cout.precision(4);
    cout << "Case " << test << ": " << fixed << h2 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
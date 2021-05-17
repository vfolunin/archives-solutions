#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double getRadius(double b, double h) {
    double a = hypot(b / 2, h);
    return (b * h) / (2 * a + b);
}

void solve(int test) {
    double b, h;
    cin >> b >> h;

    double r, rSum = 0;
    while (1) {
        r = getRadius(b, h);
        if (r < 1e-6)
            break;
        rSum += r;
        double m = (h - 2 * r) / h;
        b *= m;
        h *= m;
    }

    if (test)
        cout << "\n";
    cout << setw(13) << fixed << 2 * acos(-1) * rSum << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        solve(i);
}
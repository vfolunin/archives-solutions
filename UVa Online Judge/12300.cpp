#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double PI = acos(-1);

bool solve() {
    int xa, ya, xb, yb, n;
    cin >> xa >> ya >> xb >> yb >> n;
    
    if (!n)
        return 0;

    double dist = hypot(xa - xb, ya - yb), radius = dist / 2;
    if (n % 2) {
        double half = (n - 1) / 2;
        radius /= sin(half * PI / n);
    }

    double area = radius * radius * n / 2 * sin(2 * PI / n);

    cout.precision(6);
    cout << fixed << area << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
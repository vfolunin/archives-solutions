#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    int l = log(n);
    double x = 1 - exp(log(n) - l);

    while (fabs(x) >= 1) {
        l++;
        x = 1 - exp(log(n) - l);
    }

    cout.precision(8);
    cout << l << " " << fixed << x << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
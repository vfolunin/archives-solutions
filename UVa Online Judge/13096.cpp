#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double n;
    cin >> n;

    if (!n)
        return 0;

    double a = n * (4 * n * n - 1) / 3;
    double ab = 2 * n * n * n;
    double b = n * n * n;
    double res = sqrt((a - ab + b) / (n - 1));

    cout.precision(6);
    cout << fixed << res << '\n';
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double x = (pow(9 - sqrt(69), 1.0 / 3) + pow(9 + sqrt(69), 1.0 / 3)) / (pow(2, 1.0 / 3) * pow(3, 2.0 / 3));

bool solve() {
    double size, n;
    if (!(cin >> size >> n))
        return 0;

    double logRes = log10(size) + (n - 1) * log10(x);

    if (logRes < 9)
        cout << (int)pow(10, logRes) << "\n";
    else
        cout << (int)logRes + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
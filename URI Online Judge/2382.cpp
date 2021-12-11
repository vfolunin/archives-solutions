#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double a, b, c, r;
    cin >> a >> b >> c >> r;

    if (hypot(a / 2, b / 2, c / 2) <= r + 1e-9)
        cout << "S\n";
    else
        cout << "N\n";
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double r, n;
    if (!(cin >> r >> n))
        return 0;

    double area = n / 2 * r * r * sin(2 * acos(-1.0) / n);
    
    cout.precision(3);
    cout << fixed << area << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
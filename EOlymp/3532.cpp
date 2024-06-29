#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(int n, double radius) {
    double sum = 0;
    for (int side = 1; side <= n; side++)
        sum += acos((2 * radius * radius - side * side) / (2 * radius * radius));
    return sum <= 2 * acos(-1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    double l = 0, r = 1e9;
    for (int i = 0; i < 200; i++) {
        double m = (l + r) / 2;
        if (can(n, m))
            r = m;
        else
            l = m;
    }

    cout << fixed << r;
}
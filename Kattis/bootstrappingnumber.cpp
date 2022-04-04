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

    double x;
    cin >> x;

    double l = 1, r = x;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (pow(m, m) < x)
            l = m;
        else
            r = m;
    }

    cout << fixed << l;
}
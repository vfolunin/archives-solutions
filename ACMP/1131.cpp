#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    double l = -1e6, r = 1e6;
    for (int i = 0; i < 200; i++) {
        double m = (l + r) / 2;
        if ((a * l * l * l + b * l * l + c * l + d < 0) ==
            (a * m * m * m + b * m * m + c * m + d < 0))
            l = m;
        else
            r = m;
    }

    cout << fixed << l;
}
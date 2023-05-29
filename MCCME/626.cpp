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

    double a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < b)
        swap(a, b);
    if (c < d)
        swap(c, d);

    if (a <= c && b <= d) {
        cout << "Possible";
        return 0;
    }

    double l = 0, r = asin(1.0);
    for (int i = 0; i < 200; i++) {
        double m = (l + r) / 2;
        if (a * cos(m) + b * sin(m) > c)
            l = m;
        else
            r = m;
    }
    
    cout << (a * sin(l) + b * cos(l) <= d ? "Possible" : "Impossible");
}
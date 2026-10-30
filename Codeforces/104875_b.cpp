#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double getC(double ha, double da, double hw, double dw) {
    return (ha * ha * da + hw * hw * dw) / 2 / (ha * da + hw * dw);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double h, da, dw;
    cin >> h >> da >> da >> dw;

    double l = 0, r = h;
    for (int i = 0; i < 200; i++) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        double c1 = getC(m1, da, h - m1, dw);
        double c2 = getC(m2, da, h - m2, dw);

        if (c1 < c2)
            r = m2;
        else
            l = m1;
    }

    cout << fixed << h - l;
}
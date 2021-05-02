#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double area(double ab, double cd, double ad, double bc) {
    double a = ab - cd, b = ad, c = bc, p = (a + b + c) / 2;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    double h = 2 * s / a;
    return (ab + cd) * h / 2;
}

void solve(int test) {
    double ab, cd, ad, bc;
    cin >> ab >> cd >> ad >> bc;

    double fullArea = area(ab, cd, ad, bc);

    double l = 0, r = 1;
    for (int i = 0; i < 200; i++) {
        double m = (l + r) / 2;
        double cdm = ab - (ab - cd) * m;
        double adm = ad * m;
        double bcm = bc * m;
        if (area(ab, cdm, adm, bcm) * 2 < fullArea)
            l = m;
        else
            r = m;
    }

    cout.precision(7);
    cout << "Land #" << test << ": " << fixed << ad * l << " " << bc * l << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}
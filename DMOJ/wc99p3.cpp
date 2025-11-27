#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

bool solve() {
    double r;
    cin >> r;

    if (r == -1)
        return 0;

    static minstd_rand generator;
    double num = 0, den = 5e4;
    for (int i = 0; i < den; i++) {
        double x = uniform_real_distribution<double>(0, r)(generator);
        double y = uniform_real_distribution<double>(0, 1)(generator);
        num += y <= exp(-x * x);
    }

    cout << fixed << r * num / den << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
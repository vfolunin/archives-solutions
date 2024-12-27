#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, x, y;
    cin >> n >> x >> y;

    minstd_rand generator;
    for (int i = 0; i < n; i++) {
        double angle = uniform_real_distribution<double>(0, 2 * acos(-1))(generator);
        double radius = uniform_real_distribution<double>(0, 1)(generator);

        cout << fixed << x + cos(angle) * radius << " " << y + sin(angle) * radius << "\n";
    }
}
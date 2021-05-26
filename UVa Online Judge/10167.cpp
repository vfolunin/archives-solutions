#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

bool check(vector<pair<int, int>> &points, int a, int b) {
    int balance = 0;
    for (auto &[x, y] : points) {
        int r = a * x + b * y;
        if (!r)
            return 0;
        balance += (r > 0 ? 1 : -1);
    }
    return !balance;
}

bool solve() {
    int pointCount;
    cin >> pointCount;
    pointCount *= 2;

    if (!pointCount)
        return 0;

    vector<pair<int, int>> points(pointCount);
    for (auto &[x, y] : points)
        cin >> x >> y;

    minstd_rand gen;
    uniform_int_distribution<int> distr(-500, 500);
    int a, b;
    do {
        a = distr(gen);
        b = distr(gen);
    } while (!check(points, a, b));

    cout << a << " " << b << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const double PI = acos(-1);

bool solve() {
    double len;
    cin >> len;

    if (!len)
        return 0;

    double radius = len / PI;
    double area = PI * radius * radius / 2;

    cout.precision(2);
    cout << fixed << area << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
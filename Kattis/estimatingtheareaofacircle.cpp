#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double radius, den, num;
    cin >> radius >> den >> num;

    if (!radius)
        return 0;

    double trueArea = acos(-1) * radius * radius;
    double estimatedArea = num / den * 4 * radius * radius;

    cout << fixed << trueArea << " " << estimatedArea << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
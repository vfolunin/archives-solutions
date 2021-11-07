#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

set<int> getAngles() {
    set<int> angles;
    for (int h = 0; h < 12; h++) {
        for (int m = 0; m < 60; m++) {
            int ah = 360 / 12 * h;
            int am = 360 / 60 * m;
            int a = abs(ah - am);
            a = min(a, 360 - a);
            angles.insert(a);
        }
    }
    return angles;
}

bool solve() {
    int a;
    if (!(cin >> a))
        return 0;

    static set<int> angles = getAngles();

    cout << (angles.count(a) ? "Y\n" : "N\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
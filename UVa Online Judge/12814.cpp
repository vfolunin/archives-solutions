#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<double> num(7);
    double den = 0;

    for (int i = 0; i < 7; i++) {
        int x;
        if (!(cin >> x))
            return 0;

        if (x) {
            num[(i + 1) % 7] += 6;
            num[(i + 2) % 7] += 4;
            den += 10;
        }
    }

    cout.precision(5);
    for (int i = 0; i < 7; i++)
        cout << fixed << (den ? num[i] / den : 0) << (i + 1 < 7 ? " " : "\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}
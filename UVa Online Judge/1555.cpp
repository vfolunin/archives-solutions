#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool canBuild(vector<double> &garland) {
    for (int i = 2; i < garland.size(); i++) {
        garland[i] = 2 * (garland[i - 1] + 1) - garland[i - 2];
        if (garland[i] < 1e-6)
            return 0;
    }
    return 1;
}

bool solve() {
    int garlandSize;
    if (!(cin >> garlandSize))
        return 0;

    vector<double> garland(garlandSize);
    cin >> garland[0];

    double l = 0, r = garland[0];
    for (int i = 0; i < 300; i++) {
        garland[1] = (l + r) / 2;
        if (canBuild(garland))
            r = garland[1];
        else
            l = garland[1];
    }

    cout.precision(2);
    cout << fixed << garland.back() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}